__author__ = 'Daniel.Lee'

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        sum = 0
        for i in range(0,len(A)):
            sum = sum ^ A[i]

        return sum