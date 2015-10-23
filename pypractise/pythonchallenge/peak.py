__author__ = 'Daniel.Lee'

import pickle
import urllib2

html = urllib2.urlopen('http://www.pythonchallenge.com/pc/def/banner.p')
page = html.read()
l = pickle.loads(page)
print l

s = ''
for ml in l:
    for k in ml:
        s += k[0]*k[1]
    s += '\n'
print s