#encoding:utf8

'''
Created on 2014年10月9日

@author: Daniel.Lee
'''

d = {'blue': 5, 'yellow': 7, 'red': 3}
l = []
l.append((d['red'],'break'))
l.append((d['yellow'],'d'))
print l
print l[1]
print l[0][1]
print 'd'+'.bak'