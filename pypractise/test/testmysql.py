#encoding:utf8

'''
Created on 2014年10月9日

@author: Daniel.Lee
'''
import MySQLdb as mydb

conn = mydb.connect("localhost","root","114517","world")
c = conn.cursor()
c.execute("select * from city")
data = c.fetchall()
for d in data:
    print d
#     if d[1] == 'Puebla':
#         print d