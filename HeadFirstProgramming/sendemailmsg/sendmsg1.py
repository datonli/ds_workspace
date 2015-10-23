'''
Created on Nov 20, 2014

@author: Daniel.Lee
'''

# Import smtplib for the actual sending function
import smtplib

# Import the email modules we'll need
from email.mime.text import MIMEText

def send_msg(sender,sender_pwd,receiver,sub,msg,sender_smtp_server):
    msg = MIMEText(msg)
    msg['Subject'] = sub
    msg['From'] = sender
    msg['To'] = receiver
    s = smtplib.SMTP(timeout = 2000)
    s.connect(sender_smtp_server)
    s.login(msg['From'], sender_pwd)
    s.send_message(msg)
    s.quit()
    
def test():
    msg = 'test'
    sub = 'The contents of runtime'
#     sender_smtp_server = 'smtp.qq.com'
#     sender = '841126707@qq.com'
#     sender_pwd = 'LoveYouForever'
#     receiver = 'osDanielLee@gmail.com'
    sender_smtp_server = 'cassarry-ao1.internal.ericsson.com'
    sender = 'datong.li@ericsson.com'
    sender_pwd = 'Ericsson138'
    receiver = 'osDanielLee@gmail.com'
    send_msg(sender, sender_pwd, receiver, sub, msg, sender_smtp_server)
def run():
    textfile = r"E:\workspace\HeadFirstProgramming\sendemailmsg\textfile.txt"
    fp = open(textfile, 'r')
    text = fp.read()
    fp.close()
    msg = text
    sub = 'The contents of runtime '
    sender_smtp_server = 'smtp.qq.com'
    sender = '841126707@qq.com'
    sender_pwd = 'LoveYouForever'
    receiver = 'li.datong@mail.scut.edu.cn'
    send_msg(sender, sender_pwd, receiver, sub, msg, sender_smtp_server)
    
if __name__ == '__main__':
    test()