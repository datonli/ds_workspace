#encoding:utf8

'''
Created on 2014年10月1日

@author: Daniel.Lee
'''

class Node():
    def __init__(self,data = '#'):
        self.data = data
        self.next = None
    
class stack():
    def __init__(self,data):
        node = Node(data)
        self.top = node
        self.base = node
    
    def push(self,data):
        node = Node(data)
        node.next = self.top
        self.top = node 
        
    def pop(self):
        if self.top == self.base and self.base == None:
            return 'empty'
        elif self.top == self.base and self.base != None:
            data = self.top.data
            self.base = None
            self.top = None
            return data
        elif self.base != self.top:
            data = self.top.data
            self.top = self.top.next
            return data
    
    def empty(self):
        if self.top == self.base and self.base == None:
            return True
        else:
            return False
    
def main():
    s = stack(3)
    l = [4,2,77,1]
    for i in l:
        s.push(i)
    
    while not s.empty():
        print s.pop()

if __name__ == '__main__':
    main()
            