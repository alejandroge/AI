import numpy as np
import cv2
from matplotlib import pyplot as plt

iName = 'cuatro.bmp'
img = cv2.imread(iName, 0)

sobel = cv2.Sobel(img,cv2.CV_8U,1,1,ksize=5)
sobel = cv2.GaussianBlur(sobel,(5,5),0)
ret,thresh2 = cv2.threshold(sobel,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

str = 'b' + iName
cv2.imwrite(str, thresh2)

plt.show();
cv2.waitKey(0);
