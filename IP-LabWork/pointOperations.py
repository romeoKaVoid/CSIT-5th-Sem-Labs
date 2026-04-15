import cv2
import numpy as np

image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read image, check path")
else:
    # For Negative
    neg_img = 255 - img

    #For Log transform
    img_float = img.astype(np.float32)
    c = 255/np.log(1+np.max(img_float))
    log_trans = c * np.log(1+img_float)
    log_trans = np.array(log_trans, dtype = np.uint8)

    #For Contrast Stretching
    min_val = np.min(img)
    max_val = np.max(img)
    contrast = (img - min_val)*(255/(max_val - min_val))
    contrast = np.array(contrast, dtype=np.uint8)

    #For Thresholding
    thres_img = np.where(img>127,255,0).astype(np.uint8)
    
    #Outputs
    cv2.imshow("Original Image: Krishna Aryal",img)
    cv2.imshow("Image Negative: Krishna Aryal",neg_img)
    cv2.imshow("Log Transformed Image: Krishna Aryal",log_trans)
    cv2.imshow("Contrast Stretched Image: Krishna Aryal",contrast)
    cv2.imshow("Threshold Image: Krishna Aryal",thres_img)

    cv2.waitKey(0)
    cv2.destroyAllWindows()
