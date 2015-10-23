#encoding:utf8

'''
@author: Daniel.Lee
'''

class Node():
    def __init__(self,data = '#'):
        self.data = data
        self.next = None

class queue():
    def __init__(self,data):
        node = Node(data)
        self.front = node 
        self.rear = node 
    
    def insertRear(self,data):
        node = Node(data)
        self.rear.next = node
        self.rear = self.rear.next
        
    def delFront(self):
        if self.rear == self.front and self.rear == None:
            return 'empty'
        elif self.rear == self.front and self.rear != None:
            data = self.front.data
            self.front = None
            self.rear = None
            return data
        elif self.rear != self.front:
            data = self.front.data
            self.front = self.front.next
            return data
    
    def empty(self):
        if self.rear == self.front and self.rear == None:
            return True
        else:
            return False
        
def main():
    q = queue(6)
    l = [4,2,77,1]
    for i in l:
        q.insertRear(i)
    while not q.empty():
        print q.delFront()
        
if __name__ == '__main__':
    main()