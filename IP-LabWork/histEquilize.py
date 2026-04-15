import cv2
import numpy as np
import matplotlib.pyplot as plt

image_path = "sample2.png"
img = cv2.imread(image_path,0)

if img is None:
    print("Error: Can't read image, check path!!")
else:
    plt.hist(img.ravel(),bins=256,range=[0,256])
    plt.title("Original Histogram")
    plt.xlabel("Pixel Intensity")
    plt.ylabel("Frequency")
    plt.show()

    equalized = cv2.equalizeHist(img)

    plt.hist(equalized.ravel(),bins=256,range=[0,256])
    plt.title("Equalized Histogram")
    plt.xlabel("Pixel Intensity")
    plt.ylabel("Frequency")
    plt.show()

    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Equalized Image: Krishna Aryal", equalized)

    cv2.waitKey(0)
    cv2.destroyAllWindows()