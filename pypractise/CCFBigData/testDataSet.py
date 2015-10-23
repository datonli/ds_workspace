#encoding:utf8

'''
Created on 2014年10月9日

@author: Daniel.Lee
'''
# data = open("C:\\Users\\Daniel.Lee\\Desktop\\ccf\\train_data.txt")
data = open(r"C:\Users\Daniel.Lee\Desktop\ccf\train_data.txt")
# l = data.readlines()
# print(l[0])
lines = data.readlines()
for line in lines:
    l = line.strip().split()
#     print l
    if l[1] == '100648598':
        print(l[4])
        print l[2]
