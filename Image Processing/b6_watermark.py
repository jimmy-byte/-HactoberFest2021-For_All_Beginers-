# import all the libraries
from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw
import matplotlib.pyplot as plt
import numpy as np

# image opening
image = Image.open("puppy.jpg")
# this open the photo viewer
image.show()
plt.imshow(image)

# text Watermark
watermark_image = image.copy()

draw = ImageDraw.Draw(watermark_image)
# ("font type",font size)
font = ImageFont.truetype("arial.ttf", 50)

# add Watermark
# (0,0,0)-black color text
draw.text((0, 0), "puppy", (0, 0, 0), font=font)
plt.subplot(1, 2, 1)
plt.title("black text")
watermark_image.show()
# add Watermark
# (255,255,255)-White color text
draw.text((0, 0), "puppy", (255, 255, 255), font=font)
plt.subplot(1, 2, 2)
plt.title("white text")
watermark_image.show()
