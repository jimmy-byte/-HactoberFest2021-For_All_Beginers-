import cv2
import numpy as np
import matplotlib.pyplot as plt
import urllib.request
plt.figure(figsize=(6.4*5, 4.8*5), constrained_layout=False)
urllib.request.urlretrieve("https://ichef.bbci.co.uk/news/976/cpsprodpb/DBB7/production/_122074265_hi071843849.jpg", "l1.png")

img_c1 = cv2.imread("l1.png", 0)
img_c2 = np.fft.fft2(img_c1)
img_c3 = np.fft.fftshift(img_c2)
img_c4 = np.fft.ifftshift(img_c3)
img_c5 = np.fft.ifft2(img_c4)

plt.subplot(151), plt.imshow(img_c1, "gray"), plt.title("Original Image")
plt.subplot(152), plt.imshow(np.log(1+np.abs(img_c2)), "gray"), plt.title("Spectrum")
plt.subplot(153), plt.imshow(np.log(1+np.abs(img_c3)), "gray"), plt.title("Centered Spectrum")
plt.subplot(154), plt.imshow(np.log(1+np.abs(img_c4)), "gray"), plt.title("Decentralized")
plt.subplot(155), plt.imshow(np.abs(img_c5), "gray"), plt.title("Processed Image")

plt.show()