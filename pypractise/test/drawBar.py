#encoding:utf8

'''
Created on 2014年10月20日

@author: Daniel.Lee
'''

import numpy as np
import matplotlib.pyplot as plt
import xlrd

fname = r'D:\dACC1.xlsx'
bk = xlrd.open_workbook(fname)
shxrange = range(bk.nsheets)
try:
    sh = bk.sheet_by_name("Sheet1")
except:
    print "no sheet in %s named Sheet1" % fname
nrows = sh.nrows
ncols = sh.ncols
print "nrows %d, ncols %d" % (nrows,ncols)
 
cell_value = sh.cell_value(1,1)
print cell_value
 
row_list = []
for i in range(1,nrows):
    row_data = sh.row_values(i)
    row_list.append(row_data)

print row_list