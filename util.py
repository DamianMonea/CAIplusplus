from PIL import Image, ImageDraw
import numpy as np
import scipy.misc as smp
from scipy.misc import imsave
import random
import time
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import scipy.misc as sc

commandFile = open("COMMAND.txt", 'r')
contentFile = open("CONTENT.txt", 'r')

command = commandFile.read()
lastCommand = command

while True:
    lastCommand = command
    command = commandFile.read()
    if (command != lastCommand):
        if (command == "WAIT"):
            pass
        if (command == "DISPLAY_DIGIT"):
            tmp = contentFile.read().split(',')
            data = np.array(tmp)
            letter = np.zeros((28, 28))
            for i in range(0,28):
                for j in range(0,28):
                    letter[i,j] = int(data[28 * i + j]) 
            print(letter)
            plt.imshow(letter, cmap = 'Greys')
            plt.show()
            commandFile = open("COMMAND.txt", "w")
            commandFile.write("WAIT")
            commandFile = open("COMMAND.txt", "r")