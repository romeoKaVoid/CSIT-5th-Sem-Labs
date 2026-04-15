import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path,0)

if img is None:
    print("Error: Can't read image, check path!!")
else:
    #Mean Filter(blurring)
    mean = cv2.blur(img,(5,5))

    #Median Filter
    median = cv2.medianBlur(img, 5)

    # Outputs
    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Mean Flter: Krishna Aryal", mean)
    cv2.imshow("Median Flter: Krishna Aryal", median)

    cv2.waitKey(0)
    cv2.destroyAllWindows()