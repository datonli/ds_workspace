__author__ = 'Daniel.Lee'

from multiprocessing import Process
import os,time

def output():
    time.sleep(5)
    print 'My pid is %d' %os.getpid()
    # print "My parent's pid is %d" %os.getppid()

def main():
    p = Process(target=output)
    p.start()
    p.join()
    print "main pid is %d" %os.getpid()

if __name__ =='__main__':
    main()