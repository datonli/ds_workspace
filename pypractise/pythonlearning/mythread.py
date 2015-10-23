__author__ = 'Daniel.Lee'

import threading,time

class mythread(threading.Thread):
    def __init__(self,num):
        threading.Thread.__init__(self)
        self.num = num

    def run(self):
        if self.num < 3:
            time.sleep(self.num)
        print(self.num)

if __name__ == '__main__':
    nums = range(1,6)
    for i in nums:
        t = mythread(i)
        t.start()