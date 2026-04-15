import cv2
import numpy as np

image_path = "sample2.png"

img = cv2.imread(image_path, 0)
if img is None:
    print("Error:Can't read image, check path!!")
else:
    # Sampling (reduce resolution of image)
    sampled = cv2.resize(img, (img.shape[1]//2, img.shape[0]//2))

    # Quantization (reduce gray levels)
    levels = 4
    quantized = np.floor(img / (256 / levels)) * (256 / levels)
    quantized = quantized.astype(np.uint8)

    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Sampled Image: Krishna Aryal", sampled)
    cv2.imshow("Quantized Image: Krishna Aryal", quantized)

    cv2.waitKey(0)
    cv2.destroyAllWindows()
