
import cv2 
import numpy as np 
    
# path to input images are specified and  
# images are loaded with imread command 
image1 = cv2.imread('img3.png') 
image2 = cv2.imread('img4.png')
cv2.imshow("Original Image:1",image1)
cv2.imshow("Original Image:2",image2) 
# cv2.subtract is applied over the
# image inputs with applied parameters
sub = cv2.subtract(image1, image2)
  
# the window showing output image
# with the subtracted image 
cv2.imshow('Subtracted Image', sub)
  
# De-allocate any associated memory usage  
if cv2.waitKey(0) & 0xff == 27: 
    cv2.destroyAllWindows() 
