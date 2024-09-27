 
import cv2 
import numpy as np 
    
# path to input images are specified and  
# images are loaded with imread command 
image1 = cv2.imread('img1.png')            # imread function to read any image in the folder
image2 = cv2.imread('img2.png')
cv2.imshow("Original Image1",image1)  
cv2.imshow("Original Image2",image2)  

# cv2.addWeighted is applied over the
# image inputs with applied parameters
weightedSum = cv2.addWeighted(image1, 0.5, image2, 0.4, 0)
# Syntax: cv2.addWeighted(img1, wt1, img2, wt2, gammaValue)
# Parameters:
# img1: First Input Image array(Single-channel, 8-bit or floating-point)
# wt1: Weight of the first input image elements to be applied to the final image
# img2: Second Input Image array(Single-channel, 8-bit or floating-point)
# wt2: Weight of the second input image elements to be applied to the final image
# gammaValue: Measurement of light

# the window showing output image
# with the weighted sum 
cv2.imshow('Weighted Image', weightedSum)
# De-allocate any associated memory usage  
if cv2.waitKey(0) & 0xff == 27: 
    cv2.destroyAllWindows() 
