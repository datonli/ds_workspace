__author__ = 'Daniel.Lee'

import types,re,zipfile

num = 90052
count = 1
z = zipfile.ZipFile('E:\channel.zip')
result = ''
while type(num) is types.IntType:
    print 'time = %d,num = %d' %(count,num)
    num_str = str(num)
    result += z.getinfo(num_str + '.txt').comment
    fs = open("E:\channel\\" + num_str + ".txt")
    line = fs.read()
    line_str = line.strip().split()
    num_str = line_str[-1]
    if num_str == 'comments.':
        print result
        break
    num = int(num_str)
    count += 1
