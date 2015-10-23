#encoding:utf8

'''
Created on 2014年10月9日

@author: Daniel.Lee
'''
import csv
import sys
import os
def write2CSV(lines,filename = r'C:\Users\Daniel.Lee\Desktop\ccf\test.csv',filenamebak = r'C:\Users\Daniel.Lee\Desktop\ccf\test.csv.bak'):
    personNewsPairs = []
    persons = []
    for line in lines:
        l = line.strip().split()
        if l[0] not in persons:
            persons.append(l[0])
            personNewsPairs.append((l[0] , news))
    

    writer = csv.writer(open(filename,'w'))
#     print personNewsPairs
    for item in personNewsPairs:
        writer.writerow(item)
    os.rename(filename, filenamebak)
    with open(filenamebak, 'rU') as infile, open(filename, 'wU') as outfile:
        for line in infile:
            outfile.write(line.replace('\r'))
    os.remove(filenamebak)

def write2stdout(lines):
    personNewsPairs = []
    persons = []
    for line in lines:
        l = line.strip().split()
        if l[0] not in persons:
            persons.append(l[0])
            personNewsPairs.append((l[0] , news))
    

    writer = csv.writer(sys.stdout)
#     print personNewsPairs
    for item in personNewsPairs:
        writer.writerow(item)

data = open(r"C:\Users\Daniel.Lee\Desktop\ccf\train_data.txt")
lines = data.readlines()
maxTime = 0
count = 0
for line in lines:
    l = line.strip().split()
    count += 1
    if long(l[2]) > maxTime:
        maxTime = long(l[2])

print maxTime,count
linesOneHour = []
count = 0
for line in lines:
    l = line.strip().split()
    if (maxTime-long(l[2])) <= 7200 : 
        linesOneHour.append(line)
        count += 1
print count

newsNumMap = {}

for line in linesOneHour:
    l = line.strip().split()
    if l[1] not in newsNumMap.keys():
        newsNumMap[l[1]] = 1
    else:
        newsNumMap[l[1]] += 1

sortedNewsNumMap = sorted(newsNumMap.iteritems(), key=lambda d:d[1], reverse = True)
news = sortedNewsNumMap[0][0]
write2CSV(lines)

