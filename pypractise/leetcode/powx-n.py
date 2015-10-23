__author__ = 'Daniel.Lee'

class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float

    def pow(self, x, n):
        if n < 0: return 1/self.power(x,-n)
        return self.power(x,n)

    def power(self,x,n):
        if n == 0:
            return 1
        temp = self.pow(x,n/2)
        if n%2 == 0:
            return temp*temp
        else:
            if n > 0:
                return x*temp*temp
            else:
                return temp*temp/x

if __name__ == '__main__':
    so = Solution()
    print so.pow(34.00515, -3)