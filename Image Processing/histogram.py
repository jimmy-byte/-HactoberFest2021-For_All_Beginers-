import numpy as np
from PIL import Image
import cv2
img_filename = 'img1.png'
save_filename = 'equalized.png'


#load file as pillow Image
img = Image.open(img_filename)

# convert to grayscale
imgray = img.convert(mode='L')

#convert to NumPy array
img_array = np.asarray(imgray)

######################################
# PERFORM HISTOGRAM EQUALIZATION
######################################
"""
STEP 1: Normalized cumulative histogram
"""
#flatten image array and calculate histogram via binning
histogram_array = np.bincount(img_array.flatten(), minlength=256)
#normalize
num_pixels = np.sum(histogram_array)
histogram_array = histogram_array/num_pixels
#normalized cumulative histogram
chistogram_array = np.cumsum(histogram_array)

"""
STEP 2: Pixel mapping lookup table
"""
transform_map = np.floor(255 * chistogram_array).astype(np.uint8)

img_list = list(img_array.flatten())
# transform pixel values to equalize
eq_img_list = [transform_map[p] for p in img_list]
# reshape and write back into img_array
eq_img_array = np.reshape(np.asarray(eq_img_list), img_array.shape)


######################################
# WRITE EQUALIZED IMAGE TO FILE
######################################
#convert NumPy array to pillow Image and write to file
eq_img = Image.fromarray(eq_img_array, mode='L')
eq_img.save(save_filename)

orig_img=cv2.imread(img_filename)
final_img=cv2.imread(save_filename)
cv2.imshow("Equalized image",final_img)
cv2.imshow("Original image",orig_img)



if cv2.waitKey(0) & 0xff == 27: 
    cv2.destroyAllWindows()