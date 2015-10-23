__author__ = 'Daniel.Lee'
# -*- coding: cp936 -*-
import thread
import random
import time
import sys

aaa='' #初始用户输入变量,这个是所有线程里的全局变量,不是单个线程里的全局变量
#线程区域
##这得定义在主块里,不可在函数里定义,要不也就只是个"私有变量"了.
#下面就是"单个线程里的全局变量的定义方法,以下的response.abc就是一个这种变量了.
response=thread._local()           #这句得在主块里定义,
response.abc=1    #但这句也定义在主块里就相当于没定义过了,相看下面的#AA3
#非多线程程序可直接用'aaa'等来命名全局变量,但是"线程里的全局变量"就得是XXX.aaa了
def getit():
    #多个线程共用此函数,此函数所调用的"response.abc"就是各个线程里自已的"全局变量"
    #所以可引用,但不会被其它线程修改
    print thread.get_ident(),"getit response.id is",response.abc
def myfunction(string,sleeptime,*args):
    while 1:
#AA3 #要在定里定义才行......在这个函数块里,不是主块里..
        response.abc=random.randrange(1,20)    # 这里不可没有,主块里那句可没有,有也不起作用...
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
        aaa=sys.stdin.readline() #或用raw_input()也可的,aaa得是全局函数
        aaa=aaa[:-1] #因为输入quit后aaa的值为'quit\n' 用[:-1]去掉最后一个字符
        print 'aaa是',aaa
        if aaa=='quit':
            print "10秒后退出,这里退出的是线程了,不是整个进程"
            time.sleep(10)
            sys.exit()
        time.sleep(1)

if __name__=="__main__":
    #加线程区,想加多少就加多少
    thread.start_new_thread(myfunction,("Thread No:1",2))
    thread.start_new_thread(myfunction,("Thread No:2",2))
    thread.start_new_thread(test,('1','2')) #注意这里的test后的参数为序表('1','2'),只是起格式作用...用不着也得加一个序表形式的参数的
    while 1:
        print '主线程'
        print '主线程aaa的值是',aaa
        if aaa!='任意的':
            for i in range(10):
                print i
                time.sleep(1)
        else:
            print '输入了(任意的),退出,这里退出的才是进程'
            sys.exit()