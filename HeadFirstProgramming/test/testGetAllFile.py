'''
Created on Jan 7, 2015

@author: elidato
'''
from ftplib import FTP 

host = '10.178.255.204'
port = 21
timeout = 2000
user = 'system'
passwd = 'system'
ppDir = '/sprint_data/RawData_Bank/OMs/Access/'
ftp = FTP()
ftp.connect(host, port, timeout)
ftp.login(user, passwd)
ftp.cwd(ppDir)
print(ftp.isDir('./knoxNas_26/temp/'))
print(ftp.sendcmd('HELP'))
# for m in ftp.mlsd('./knoxNas_26/temp/', ['type']):
#     print(m[0] + " " + m[1]['type'])
# ftp.retrlines("LIST", lambda l:pDirName.append(l.split()[-1]))