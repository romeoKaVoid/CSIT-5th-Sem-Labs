import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read image, check path!!")
else:
    # Line detection masks
    horizontal_mask = np.array([[-1, -1, -1], [2, 2, 2], [-1, -1, -1]])
    vertical_mask = np.array([[-1, 2, -1], [-1, 2, -1], [-1, 2, -1]])

    # Apply line detection
    hor_line_detect = cv2.filter2D(img, -1, horizontal_mask)
    vert_line_detect = cv2.filter2D(img, -1, vertical_mask)

    # Edge detection (Sobel and Canny)
    sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
    sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)

    sobelx_abs = cv2.convertScaleAbs(sobelx)
    sobely_abs = cv2.convertScaleAbs(sobely)

    sobel_comb = cv2.addWeighted(sobelx_abs, 0.5, sobely_abs, 0.5, 0)
    canny_edges = cv2.Canny(img, 100, 200)

    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Horizontal Line Detection: Krishna Aryal", hor_line_detect)
    cv2.imshow("Vertical Line Detection: Krishna Aryal", vert_line_detect)
    cv2.imshow("Sobel Edge Detection: Krishna Aryal", sobel_comb)
    cv2.imshow("Canny Edge Detection: Krishna Aryal", canny_edges)

    cv2.waitKey(0)
    cv2.destroyAllWindows()