import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read image, check path!!")
else:
    # Gaussian Noise
    mean = 0
    sd = 25
    gaussian = img + np.random.normal(mean, sd, img.shape)
    gaussian = np.clip(gaussian, 0, 255).astype(np.uint8)

    # Salt & Pepper Noise
    sp = img.copy()
    prob = 0.02
    rows = img.shape[0]
    cols = img.shape[1]
    for i in range(rows):
        for j in range(cols):
            r = np.random.rand()
            if r < prob:
                sp[i][j] = 0
            elif r > 1 - prob:
                sp[i][j] = 255

    # Restore using filtering
    gaussian_filtered = cv2.GaussianBlur(gaussian,(5,5),1)
    sp_filtered = cv2.medianBlur(sp, 5)

    # Display Images
    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Gaussian Noise: Krishna Aryal", gaussian)
    cv2.imshow("Gaussian Filtered: Krishna Aryal", gaussian_filtered)
    cv2.imshow("Salt & Pepper Noise : Krishna Aryal", sp)
    cv2.imshow("Salt & Pepper Filtered: Krishna Aryal", sp_filtered)

    cv2.waitKey(0)
    cv2.destroyAllWindows()