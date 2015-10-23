#encoding:utf8

'''
Created on 2014年10月9日

@author: Daniel.Lee
'''
import smtplib

sender = 'osDanielLee@gmail.com'
receivers = ['841126707@qq.com']

message = """From: From Person <from@fromdomain.com>
To: To Person <to@todomain.com>
Subject: SMTP e-mail test

This is a test e-mail message.
"""

smtpObj = smtplib.SMTP('localhost')
smtpObj.sendmail(sender, receivers, message)         
print "Successfully sent email"
