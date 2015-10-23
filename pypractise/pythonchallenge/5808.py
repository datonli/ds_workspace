__author__ = 'Daniel.Lee'
from PIL import Image, ImageDraw

im = Image.open('E:\cave.jpg')
w,h = im.size
for i in range(w):
    for j in range(h):
        if (i+j)%2 == 1:
            im.putpixel((i,j),0)
im.show()