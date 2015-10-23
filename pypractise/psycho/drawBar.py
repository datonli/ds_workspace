#encoding:utf8

'''
Created on 2014年10月20日

@author: Daniel.Lee
'''

import matplotlib.pyplot as plt
from cProfile import label

x = []
y = []

data = open(r'D:\dacc1.txt')
for line in data.readlines():
    l = line.split()
    print l
    x.append(float(l[0]))
    y.append(float(l[1]))
x = sum(x)/len(x)
y = sum(y)/len(y)

plt.figure()
plt.bar(-1,x,label = "$A$")
plt.bar(1,y)
plt.show()