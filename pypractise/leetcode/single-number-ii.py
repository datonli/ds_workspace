__author__ = 'Daniel.Lee'

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        ones = 0
        twos = 0
        for i in range(0,len(A)):
            ones = (ones ^ A[i]) & ~twos
            twos = (twos ^ A[i]) & ~ones
        return ones