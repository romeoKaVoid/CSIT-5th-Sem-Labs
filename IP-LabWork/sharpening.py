import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read image, check path")
else:
   # Laplacian Filtering
    lap = cv2.Laplacian(img, cv2.CV_64F)
    lap_abs = cv2.convertScaleAbs(lap)
    sharp_lap = cv2.subtract(img,lap_abs)
    
    # Sobel Filtering
    sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
    sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)

    sobelx_abs = cv2.convertScaleAbs(sobelx)
    sobely_abs = cv2.convertScaleAbs(sobely)

    sobel_comb = cv2.addWeighted(sobelx_abs, 0.5, sobely_abs, 0.5, 0)
    sharp_sobel = cv2.addWeighted(img, 1.0, sobel_comb, 1.0, 0)

    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Laplacian: Krishna Aryal", lap_abs)
    cv2.imshow("Sharpened by Laplacian: Krishna Aryal", sharp_lap)
    cv2.imshow("Sobel: Krishna Aryal", sobel_comb)
    cv2.imshow("Sharpened by Sobel: Krishna Ayal", sharp_sobel)

    cv2.waitKey(0)
    cv2.destroyAllWindows()