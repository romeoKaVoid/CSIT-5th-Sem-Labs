import cv2
import numpy as np
import matplotlib.pyplot as plt

image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read image, check path")
else:
    # Compute FFT and shift low freq to center
    f = np.fft.fft2(img)
    fshift = np.fft.fftshift(f)

    # Magnitude Spectrum
    magnitude = 20 * np.log(np.abs(fshift))

    # Low Pass Filter
    rows, cols = img.shape
    center_row = rows//2
    center_col = cols//2

    mask = np.zeros((rows, cols), np.uint8)
    radius = 30

    for i in range(rows):
        for j in range(cols):
            distance = np.sqrt((i - center_row) ** 2 + (j - center_col) ** 2)
            if distance <= radius:
                mask[i, j] = 1

    fshift_filt = fshift * mask

    # Inverse FFT
    f_ishift = np.fft.ifftshift(fshift_filt)
    img_back = np.fft.ifft2(f_ishift)
    img_back = np.abs(img_back)

    #Display using matplotlib
    plt.figure(figsize=(12,8))
    plt.title("Krishna Aryal")
    plt.axis("off")

    plt.subplot(2, 2, 1)
    plt.title("Original Image")
    plt.imshow(img, cmap="gray")
    plt.axis("off")

    plt.subplot(2, 2, 2)
    plt.title("Magnitude Spectrum")
    plt.imshow(magnitude, cmap="gray")
    plt.axis("off")

    plt.subplot(2, 2, 3)
    plt.title("Filtered Image")
    plt.imshow(img_back, cmap="gray")
    plt.axis("off")

    plt.tight_layout()
    plt.show()