import cv2
import numpy as np

image_path = "sample2.png"

img = cv2.imread(image_path, 0)
if img is None:
    print("Error:Can't read image, check path!!")
else:
    rows = img.shape[0]
    cols = img.shape[1]

    print("Image size:", rows, "x", cols)

    p1 = (100,100)
    p2 = (150,150)

    #Euclidean Dostance
    euclidean = np.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)
    #Manhattan Distance
    manhattan = abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])

    print("Pixel 1:", p1)
    print("Pixel 2:", p2)
    print(f"\nEuclidean Distance: {euclidean:.4f}")
    print("Manhattan Distance:", manhattan)

    #Show neighbors of p1
    x,y = p1;
    n4 = [(x-1,y),(x+1,y),(x,y-1),(x,y+1)]
    n8 = n4 + [(x-1,y-1),(x-1,y+1),(x+1,y-1),(x+1,y+1)]

    print("4 Neighbors: ", n4)
    print("8 Neighbors: ", n8)
    print("\n  -By Krishna Aryal")