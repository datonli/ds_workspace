__author__ = 'Daniel.Lee'
# -*- coding: cp936 -*-
import thread
import random
import time
import sys

aaa='' #��ʼ�û��������,����������߳����ȫ�ֱ���,���ǵ����߳����ȫ�ֱ���
#�߳�����
##��ö�����������,�����ں����ﶨ��,Ҫ��Ҳ��ֻ�Ǹ�"˽�б���"��.
#�������"�����߳����ȫ�ֱ����Ķ��巽��,���µ�response.abc����һ�����ֱ�����.
response=thread._local()           #�����������ﶨ��,
response.abc=1    #�����Ҳ��������������൱��û�������,�࿴�����#AA3
#�Ƕ��̳߳����ֱ����'aaa'��������ȫ�ֱ���,����"�߳����ȫ�ֱ���"�͵���XXX.aaa��
def getit():
    #����̹߳��ô˺���,�˺��������õ�"response.abc"���Ǹ����߳������ѵ�"ȫ�ֱ���"
    #���Կ�����,�����ᱻ�����߳��޸�
    print thread.get_ident(),"getit response.id is",response.abc
def myfunction(string,sleeptime,*args):
    while 1:
#AA3 #Ҫ�ڶ��ﶨ�����......�������������,����������..
        response.abc=random.randrange(1,20)    # ���ﲻ��û��,�������Ǿ��û��,��Ҳ��������...
        print string,"response.abc is",response.abc
        arg1=random.randrange(1,6)
        time.sleep(arg1)
        getit()
        time.sleep(sleeptime) #sleep for a specified amount of time.
        if aaa=='quit':
            sys.exit()
def test(x,y):
    print x,y
    global aaa
    while 1:
        aaa=sys.stdin.readline() #����raw_input()Ҳ�ɵ�,aaa����ȫ�ֺ���
        aaa=aaa[:-1] #��Ϊ����quit��aaa��ֵΪ'quit\n' ��[:-1]ȥ�����һ���ַ�
        print 'aaa��',aaa
        if aaa=='quit':
            print "10����˳�,�����˳������߳���,������������"
            time.sleep(10)
            sys.exit()
        time.sleep(1)

if __name__=="__main__":
    #���߳���,��Ӷ��پͼӶ���
    thread.start_new_thread(myfunction,("Thread No:1",2))
    thread.start_new_thread(myfunction,("Thread No:2",2))
    thread.start_new_thread(test,('1','2')) #ע�������test��Ĳ���Ϊ���('1','2'),ֻ�����ʽ����...�ò���Ҳ�ü�һ�������ʽ�Ĳ�����
    while 1:
        print '���߳�'
        print '���߳�aaa��ֵ��',aaa
        if aaa!='�����':
            for i in range(10):
                print i
                time.sleep(1)
        else:
            print '������(�����),�˳�,�����˳��Ĳ��ǽ���'
            sys.exit()