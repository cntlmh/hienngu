#------------------------- Testing 1 --------------------------
print("------------------------- Testing 1 --------------------------")
import onnx
import onnx.checker
model = onnx.load("mpvitnet.onnx")
onnx.checker.check_model(model)
print("ONNX model check passed")


#------------------------- Testing 2 --------------------------
print("------------------------- Testing 2 --------------------------")
import onnxruntime as ort
import numpy as np
session = ort.InferenceSession("mpvitnet.onnx")
input_data = np.random.randn(1, 3, 320, 1024).astype(np.float32)
outputs = session.run(None, {"input": input_data})
print(outputs[0].shape)

#------------------------- Testing 3 --------------------------
print("------------------------- Testing 3 --------------------------")
import onnxruntime as ort
import numpy as np
import cv2
from PIL import Image
import matplotlib.pyplot as plt

# Hàm chuẩn bị ảnh đầu vào
def preprocess_image(image_path, target_size=(320, 1024)):
    # Đọc ảnh
    img = Image.open(image_path).convert('RGB')
    
    # Resize về kích thước mục tiêu
    img = img.resize(target_size, Image.BILINEAR)
    
    # Chuyển sang numpy array
    img = np.array(img).astype(np.float32)
    
    # Chuyển từ [H, W, C] sang [C, H, W]
    img = img.transpose(2, 0, 1)
    
    # Chuẩn hóa (nếu mô hình yêu cầu, ví dụ: mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])
    # Điều chỉnh mean/std nếu bạn biết giá trị từ training
    img = img / 255.0  # Scale về [0, 1]
    # img = (img - np.array([0.5, 0.5, 0.5]).reshape(3, 1, 1)) / np.array([0.5, 0.5, 0.5]).reshape(3, 1, 1)
    
    # Thêm batch dimension: [1, C, H, W]
    img = img[np.newaxis, ...]
    
    return img

# Hàm chuyển disparity sang depth
def disp_to_depth(disp, min_depth=1e-3, max_depth=80):
    # Loại bỏ batch và channel dimension
    disp = disp.squeeze(0).squeeze(0)  # [H, W]
    
    # Chuyển disparity sang depth
    pred_depth = 1 / disp
    
    # Giới hạn depth
    pred_depth = np.clip(pred_depth, min_depth, max_depth)
    
    return pred_depth

# Hàm lưu và hiển thị depth map
def save_and_show_depth(depth, output_path="depth_map.png"):
    # Chuẩn hóa depth để hiển thị (scale về [0, 1])
    depth_normalized = (depth - depth.min()) / (depth.max() - depth.min())
    
    # Áp dụng colormap
    depth_colored = cv2.applyColorMap((depth_normalized * 255).astype(np.uint8), cv2.COLORMAP_JET)
    
    # Lưu depth map
    cv2.imwrite(output_path, depth_colored)
    print(f"Depth map saved to {output_path}")
    
    # Hiển thị
    plt.figure(figsize=(10, 5))
    plt.imshow(depth_colored[:, :, ::-1])  # Chuyển BGR sang RGB
    plt.title("Depth Map")
    plt.axis('off')
    plt.show()

# Main
def main(image_path, onnx_path="mpvitnet2.onnx"):
    # Load mô hình ONNX
    session = ort.InferenceSession(onnx_path, providers=['CPUExecutionProvider'])
    
    # Chuẩn bị ảnh đầu vào
    input_data = preprocess_image(image_path, target_size=(1024, 320))
    
    # Chạy suy luận
    outputs = session.run(None, {"input": input_data})
    disp = outputs[0]  # [1, 1, 320, 1024]
    
    # Chuyển disparity sang depth
    depth = disp_to_depth(disp)
    
    # Lưu và hiển thị depth map
    save_and_show_depth(depth)
    print("Done")

if __name__ == "__main__":
    # Đường dẫn đến ảnh đầu vào
    image_path = "output.jpg"  # Thay bằng đường dẫn ảnh của bạn
    main(image_path)