__author__ = 'Daniel.Lee'

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        if n == 0 or n == 1 or n == 2:
            return n
        l = []
        l.append(1)
        l.append(2)
        for i in range(2,n):
            l.append(l[i-1] + l[i-2])
        return l[-1]