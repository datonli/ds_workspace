#encoding:utf8

'''
Created on 2014年10月1日

@author: Daniel.Lee
'''
class Node():
    def __init__(self,data = '#'):
        self.data = data
        self.next = None
    
class LinkedList():
    def create(self,s = '#'):
        head = Node()
        head.data = 0
        p = head
        if s != '#':
            ss = s.split()
            for i in range(len(ss)):
                p.next = Node(int(ss[i]))
                p = p.next
        else:
            print 'Please enter your node data:'
            x = raw_input()
            while x != '#':
                x = int(x)
                p.next = Node(x)
                p = p.next
                x = raw_input()
        return head
    
    def printLinkedList(self,head):
        p = head.next
        while p != None:
            print p.data,
            p = p.next
        else:
            print '\nend'
            
    def length(self,head):
        p = head.next
        count = 0
        while p != None:
            count += 1
            p = p.next
        return count 
    
    def delnum(self,head,num):
        pp = head
        p = pp.next
        if p.data == num:
            head = p
            pp.next = None
        else:
            pp = p
            p = p.next
            while p != None:
                if p.data == num:
                  pp.next = p.next
                  p.next = None   
                  break
                else:
                    pp = p
                    p = p.next
            else:
                print 'linkedList has end,I bet you enter a wrong num'
        return head
    
    def insert(self,head,index,num):
        p = head
        pp = None
        while index != 0 :
            pp = p
            p = p.next
            if p == None:
                print 'Sorry,out of index'
                return head
            index -= 1
        pp.next = Node(num)
        pp.next.next = p
        return head
    
def main():
    l = LinkedList()
    head = l.create('1 3 5 6 ')
    l.printLinkedList(head)
    print l.length(head)
    head = l.delnum(head,1)
    l.printLinkedList(head)
    head = l.insert(head, 3, 4)
    l.printLinkedList(head)
    
if __name__ == '__main__':
    main()