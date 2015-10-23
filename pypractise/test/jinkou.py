#encoding:utf8

'''
Created on 2014年10月8日

@author: Daniel.Lee
'''

import matplotlib.pyplot as mpl
x = []
y = []
for line in open('E:\jinkou.txt').readlines():
    l = line.strip().split(' ')
    x.append(int(l[0]))
    y.append(int(l[3]))
     
mpl.figure()
mpl.plot(x,y)
mpl.show()
