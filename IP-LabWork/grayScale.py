import cv2

image_path = "sample2.png"

img = cv2.imread(image_path, cv2.IMREAD_COLOR)
if img is None:
    print("Error:Can't read image, check path!!")
else:
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    #Properties
    print("Image Properties")
    print("-------------------")
    print("Shape (Height, Width, Channels):", img.shape)
    print("Min Intensity: ",gray.min())
    print("Max Intensity: ", gray.max())

    print("Total Pixels:", img.size)

    #Display Images
    cv2.imshow("Original Image: Krishna Aryal", img)
    cv2.imshow("Graycale Image: Krishna Aryal ",gray)
    cv2.waitKey(0)
    cv2.destroyAllWindows()