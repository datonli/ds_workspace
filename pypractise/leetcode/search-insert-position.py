__author__ = 'Daniel.Lee'
class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        if A == []:
            return 0
        for i in range(len(A)):
            if target <= A[i]:
                return i
            elif target > A[i] and (i+1)==len(A):
                return i+1


if __name__ == '__main__':
    A = [1,2,4,5]
    print Solution().searchInsert(A,3)