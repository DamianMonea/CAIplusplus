from PIL import Image, ImageDraw
import numpy as np
import scipy.misc as smp
from scipy.misc import imsave
import random
import time
import sys
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import scipy.misc as sc

contentFile = open("CONTENT.txt", 'r')

command = sys.argv[1]
if (command == "DISPLAY_DIGIT"):
    tmp = contentFile.read().split(',')
    data = np.array(tmp)
    letter = np.zeros((28, 28))
    for i in range(0,28):
        for j in range(0,28):
            if (data[28 * i + j] != ''):
                letter[i,j] = int(data[28 * i + j]) 
    plt.imshow(letter, cmap = 'Greys')
    plt.show()
contentFile.close()