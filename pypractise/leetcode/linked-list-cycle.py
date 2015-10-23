__author__ = 'Daniel.Lee'
class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        flag = head
        if head:
            if not head.next:
                return False
            head = head.next
        else:
            return False
        while head :
            if head == flag:
                return True
            head = head.next
        return False