'''
Created on Nov 24, 2014

@author: elidato
'''
from ftplib import FTP
import time

wholeHours = ['00', '01', '02', '03', '04', '05', '06',
              '07', '08', '09', '10', '11', '12', '13',
              '14', '15', '16', '17', '18', '19', '20', '21', '22', '23' ]

wholeMinutes = ['00','30']

ftp = FTP()

def dealTarFile(fileName, fileTypeDateMap):
    fileNameSplit = fileName.split('-')
    day = fileNameSplit[1]
    dayHourMap = {}
    dayHourMap[day] = wholeHours
    if str(fileNameSplit[0]) not in fileTypeDateMap.keys():
        fileTypeDateMap[fileNameSplit[0]] = dayHourMap
    else:
        fileTypeDateMap[fileNameSplit[0]][day] = wholeHours
    return fileTypeDateMap

def dealGzFile(fileName, fileTypeDateMap):    
    fileNameSplit = fileName.split('_')
    day = str(fileNameSplit[-2])
    hour = str(fileNameSplit[-1])
    if str(fileNameSplit[2]) not in fileTypeDateMap.keys():
        fileTypeDateMap[fileNameSplit[2]] = {day:[hour, ]}
    else:
        if day not in fileTypeDateMap[fileNameSplit[2]]:
            fileTypeDateMap[fileNameSplit[2]][day] = [hour, ]
        else:
            if hour not in fileTypeDateMap[fileNameSplit[2]][day]:
                fileTypeDateMap[fileNameSplit[2]][day].append(hour)
    return fileTypeDateMap

def dealNoExtFile(fileName, fileTypeDateMap):
    if(ftp.isDir(fileName)):
        ftp.cwd('./' + fileName)
    else:
        return fileTypeDateMap
    fileList = ftp.nlst()
    for fileName in fileList:
        fileNameSplit = fileName.split('-')
        day = str(fileNameSplit[-1])[:8]
        hour = str(fileNameSplit[-1])[8:10]
        #minute = str(fileNameSplit[-1])[8:10]
        if str(fileNameSplit[0]) not in fileTypeDateMap.keys():
            fileTypeDateMap[fileNameSplit[0]] = {day:[hour, ]}
        else:
            if day not in fileTypeDateMap[fileNameSplit[0]]:
                fileTypeDateMap[fileNameSplit[0]][day] = [hour, ]
            else:
                if hour not in fileTypeDateMap[fileNameSplit[0]][day]:
                    fileTypeDateMap[fileNameSplit[0]][day].append(hour)
    return fileTypeDateMap



def getFtpDirInfo(host, port, timeout, user, passwd, ppDir): 
    pDirName = []
    dirFileMap = {}
    ftp.connect(host, port, timeout)
    ftp.login(user, passwd)
    ftp.cwd(ppDir)
    ftp.retrlines("LIST", lambda l:pDirName.append(l.split()[-1]))
    for dirName in pDirName:
        if ((dirName == "knoxNas_26")): #\
#             or (dirName == "knoxNas_29") \
#             or (dirName == "johnNas_25")  or (dirName == "louiNas_28") \
#             or (dirName == "louiNas_27")):
            ftp.cwd(ppDir + dirName + "/")
            dirFileMap[dirName] = ftp.nlst()
            print(ftp.mlsd("./temp", ['type']))
    return dirFileMap


def getLackingInfo(dirFileMap):
    existedFile = {}
    for dirName in dirFileMap.keys():
        lists = dirFileMap[dirName]
        fileTypeDateMap = {}
        for wholeFileName in lists:
            wholeFileNameSplit = wholeFileName.split('.')
            fileNameExtension = wholeFileNameSplit[-1]
            if fileNameExtension == 'tar':
                fileTypeDateMap = dealTarFile(wholeFileNameSplit[0], fileTypeDateMap)
            elif fileNameExtension == 'gz':
                fileTypeDateMap = dealGzFile(wholeFileNameSplit[0], fileTypeDateMap)
            else:
                fileTypeDateMap = dealNoExtFile(wholeFileNameSplit[0], fileTypeDateMap)
        existedFile[dirName] = fileTypeDateMap.copy()   
        fileTypeDateMap.clear()
#     print('print existedFile map')
#     pprint.pprint(existedFile)
    
    lackingInfo = []
    for site in existedFile.keys():
        for fileType in existedFile[site].keys():
            days = list(existedFile[site][fileType].keys())
            days.sort()
            minDay = days[0]
            maxDay = days[-1]
            for day in existedFile[site][fileType].keys():
                if day == minDay:
                    hours = existedFile[site][fileType][minDay]
                    hours.sort()
                    minHour = hours[0]
                    for hour in wholeHours[wholeHours.index(minHour,):]:
                        if hour not in existedFile[site][fileType][day]:
                            lackingInfo.append(site + '_' + fileType + '_' + day + '_' + hour)
                elif day == maxDay:
                    hours = existedFile[site][fileType][maxDay]
                    hours.sort()
                    maxHour = hours[-1]
                    for hour in wholeHours[:wholeHours.index(maxHour,)]:
                        if hour not in existedFile[site][fileType][day]:
                            lackingInfo.append(site + '_' + fileType + '_' + day + '_' + hour)
                else:
                    for hour in wholeHours:
                        if hour not in existedFile[site][fileType][day]:
                            lackingInfo.append(site + '_' + fileType + '_' + day + '_' + hour)
    return lackingInfo    
    

def main():
    host = '10.178.255.204'
    port = 21
    timeout = 2000
    user = 'system'
    passwd = 'system'
    ppDir = '/sprint_data/RawData_Bank/OMs/Access/'
    
    
    dirFileMap = getFtpDirInfo(host, port, timeout, user, passwd, ppDir)
    print(dirFileMap)
    lackingInfo = getLackingInfo(dirFileMap)
    lackingInfo.sort()
#     pprint.pprint(lackingInfo)
    lackingStrInfo = ''
    for lackingFile in lackingInfo:
        lackingStrInfo += lackingFile + '\n'
    #print(lackingStrInfo)
    ftp.quit()
    time_now = str(time.ctime())
    
    textpath = 'C:\\Users\\elidato\\Desktop\\lackingLogs.txt'
    fp = open(textpath, 'w')
    fp.write('Checking time is :      ' + time_now + '\n' + lackingStrInfo)
    fp.close()
    
    
if __name__ == '__main__':
    main()
