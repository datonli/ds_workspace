#encoding:utf8

'''
Created on 2014年10月8日

@author: Daniel.Lee
'''

import matplotlib.pyplot as mpl
x = []
y = []
for line in open('E:\hongkong.txt').readlines():
    l = line.strip().split(' ')
    x.append(int(l[0]))
    y.append(int(l[3]))
     
mpl.figure()
mpl.plot(x,y)
mpl.title('hongkong')


x = []
y = []
for line in open('E:\chukou.txt').readlines():
    l = line.strip().split(' ')
    x.append(int(l[0]))
    y.append(int(l[3]))
     
mpl.figure()
mpl.hold()
mpl.plot(x,y)
# mpl.title('chukou')

x = []
y = []
for line in open('E:\jinkou.txt').readlines():
    l = line.strip().split(' ')
    x.append(int(l[0]))
    y.append(int(l[3]))
     
# mpl.figure()
mpl.hold()
mpl.plot(x,y)
# mpl.title('jinkou')

x = []
y = []
for line in open('E:\hkzong.txt').readlines():
    l = line.strip().split(' ')
    x.append(int(l[0]))
    y.append(int(l[6]))
     
mpl.figure()
mpl.plot(x,y)
mpl.title('hkzong')


mpl.show()
