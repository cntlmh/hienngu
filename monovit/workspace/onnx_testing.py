import onnxruntime as ort
import numpy as np
import cv2
import matplotlib.pyplot as plt

# pre-processing images
img_path = "assets/test_image.jpg"
img = cv2.imread(img_path)

if img is None:
    raise FileNotFoundError(f"Không tìm thấy ảnh: {img_path}")

# Resize and convert BGR -> RGB
img = cv2.resize(img, (640, 192))
img = img[:, :, ::-1].astype(np.float32) / 255.0  # RGB and normalize
img = img.transpose(2, 0, 1)[None, :, :, :]  # (1, 3, H, W)

# load model ONNX
session = ort.InferenceSession("weight/monodepth_fixed640x192.onnx")
output = session.run(None, {"input": img})

# result of disparity
disp = output[0][0, 0]  # (192, 640)
disp = np.clip(disp, 1e-6, None)

# calcualte depth from disparity
depth = 1.0 / disp

# normalize disparity and depth for visualization
disp_vis = disp / np.max(disp)
depth_vis = depth / np.max(depth)

# display with colorbar
fig, axs = plt.subplots(1, 2, figsize=(12, 5))

# Disparity
im0 = axs[0].imshow(disp_vis, cmap='plasma')
axs[0].set_title("Predicted Disparity")
axs[0].axis('off')
cbar0 = plt.colorbar(im0, ax=axs[0], fraction=0.046, pad=0.04)
cbar0.set_label("Normalized Disparity", rotation=270, labelpad=15)

# Depth
im1 = axs[1].imshow(depth_vis, cmap='inferno')
axs[1].set_title("Predicted Depth")
axs[1].axis('off')
cbar1 = plt.colorbar(im1, ax=axs[1], fraction=0.046, pad=0.04)
cbar1.set_label("Normalized Depth", rotation=270, labelpad=15)

# saving and showing
plt.tight_layout()
plt.savefig("output_disp_depth_colored.png")
plt.show()
