__author__ = 'Daniel.Lee'
class Solution:
    # @return an integer
    def reverse(self, x):
        if x == 0:
            return 0
        return int(''.join(reversed(str(abs(x)))))*(abs(x)/x)

if __name__ == '__main__':
    print Solution().reverse(-100)