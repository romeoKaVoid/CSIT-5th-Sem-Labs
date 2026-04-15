import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path,0)

if img is None:
    print("Error: Can't read image, check path")
else:
    cv2.imshow("Original Image: Krishna Aryal",img)
    for i in range(8):
        bit_plane = (img >> i) & 1
        bit_plane = bit_plane * 255  # make visible
        cv2.imshow(f"Bit Plane {i}: Krishna Aryal", bit_plane.astype(np.uint8))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
