import onnxruntime as ort
import numpy as np
import cv2
import os
from PIL import Image
import torchvision.transforms.functional as TF
import matplotlib.pyplot as plt

# --- Cấu hình ---
ONNX_PATH = "dac_swinl_outdoor.onnx"
IMG_DIR = "input_test"        # Thư mục chứa ảnh đầu vào
OUT_DIR = "depth_results"      # Thư mục lưu kết quả
INPUT_SIZE = (1216, 352)       # Phải khớp với fwd_sz khi export

os.makedirs(OUT_DIR, exist_ok=True)

# --- Load model ONNX ---
session = ort.InferenceSession(ONNX_PATH, providers=["CPUExecutionProvider"])
input_name = session.get_inputs()[0].name
output_name = session.get_outputs()[0].name

# --- Hàm xử lý ảnh ---
def preprocess_image(image_path):
    img = Image.open(image_path).convert("RGB")
    img = img.resize(INPUT_SIZE)
    img_tensor = TF.to_tensor(img)
    img_tensor = TF.normalize(img_tensor, mean=[0.485, 0.456, 0.406],
                                         std=[0.229, 0.224, 0.225])
    return img_tensor.unsqueeze(0).numpy()

def postprocess_depth(depth):
    # Giả sử Depth Pred là đầu ra của model có 1 kênh
    depth = depth[0, 0]  # Chỉ lấy kênh thứ nhất (depth prediction)
    depth = (depth - depth.min()) / (depth.max() - depth.min() + 1e-6)
    depth = (depth * 255).astype(np.uint8)  # Chuyển đổi lại thành dạng 8-bit cho ảnh
    return depth

def postprocess_areal(a_rel):
    # Nếu A. Rel là đầu ra, chuyển nó về giá trị hình ảnh có thể nhìn được
    a_rel = a_rel[0, 0]  # Nếu nó là 1 kênh
    a_rel = (a_rel - a_rel.min()) / (a_rel.max() - a_rel.min() + 1e-6)
    a_rel = (a_rel * 255).astype(np.uint8)  # Chuyển thành ảnh 8-bit
    return a_rel

# --- Duyệt toàn bộ ảnh trong thư mục ---
for img_name in os.listdir(IMG_DIR):
    img_path = os.path.join(IMG_DIR, img_name)
    if not img_path.lower().endswith(('.jpg', '.png', '.jpeg')):  # Chỉ xử lý ảnh
        continue

    # Tiền xử lý ảnh đầu vào
    inp = preprocess_image(img_path)

    # Lấy đầu ra từ mô hình ONNX
    outputs = session.run([output_name], {input_name: inp})[0]

    # Kiểm tra kích thước và giá trị của đầu ra
    print(f"Output shape: {outputs.shape}")
    print(f"Output min/max: {outputs.min()}, {outputs.max()}")

    # Xử lý ảnh đầu ra là Depth Pred
    depth_map = postprocess_depth(outputs)

    # Hiển thị và lưu ảnh depth map
    out_path = os.path.join(OUT_DIR, os.path.splitext(img_name)[0] + "_depth.png")
    cv2.imwrite(out_path, depth_map)
    print(f"✅ Đã xử lý Depth Pred: {img_name} -> {out_path}")

    # Hiển thị hình ảnh depth map
    plt.imshow(depth_map, cmap='plasma')
    plt.title(f"Depth Pred - {img_name}")
    plt.show()
