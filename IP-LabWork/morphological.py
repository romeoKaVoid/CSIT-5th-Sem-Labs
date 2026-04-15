import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read image, check path!!")
else:
    # Convert to binary
    _, binary = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)

    #S.E.
    kernel = np.ones((5,5), np.uint8)

    # Operations
    dilation = cv2.dilate(binary, kernel, iterations=1)
    erosion = cv2.erode(binary, kernel, iterations=1)
    opening = cv2.morphologyEx(binary, cv2.MORPH_OPEN, kernel)
    closing = cv2.morphologyEx(binary, cv2.MORPH_CLOSE, kernel)

    cv2.imshow("Original Image: Krishna Aryal",img)
    cv2.imshow("Binary: Krishna Aryal", binary)
    cv2.imshow("Dilation: Krishna Aryal", dilation)
    cv2.imshow("Erosion: Krishna Aryal", erosion)
    cv2.imshow("Opening: Krishna Aryal", opening)
    cv2.imshow("Closing: Krishna Aryal", closing)

    cv2.waitKey(0)
    cv2.destroyAllWindows()