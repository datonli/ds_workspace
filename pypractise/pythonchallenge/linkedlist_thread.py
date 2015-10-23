__author__ = 'Daniel.Lee'
import urllib2
import thread

num = 8022
count = 86

def solve_thread():
    while count != 400:
    html = urllib2.urlopen('http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing=' + str(num))
    page = html.read()
    num = int(page.strip().split()[-1])
    print "time = %d,num = %d" %(count,num)
    count += 1