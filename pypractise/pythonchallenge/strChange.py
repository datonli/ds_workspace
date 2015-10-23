__author__ = 'Daniel.Lee'

s = "map"
mc = {'m': "k",'q':"o",'g':"e"}

ns = []

for k in range(0,len(s)):
    if ord(s[k]) >= 97 and ord(s[k]) <= 122:
        num = ord(s[k])+2
    else:
        num = ord(s[k])
    if num > 122:
        num -= 26
    ns.append(chr(num))



print ''.join(ns.__iter__())