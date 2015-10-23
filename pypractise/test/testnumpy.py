'''
Created on 2014/9/22

@author: Daniel.Lee
'''
from numpy import * 


randMat = mat(random.rand(4,4))
print randMat
print randMat.I
print randMat*randMat.I
print eye(4)

a = array([1,2])
b = array([2,2])
c = 2
print a/b
print a/c
print tile(1,(1,1000))