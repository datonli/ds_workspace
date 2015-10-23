__author__ = 'Daniel.Lee'
class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        flag = False
        profit = 0
        if len(prices) < 2:
            return 0
        if prices[0] <= prices[1]:
            flag = True
        for i in range(1,len(prices)):
            if (not flag) and (prices[i] >= prices[i-1]):
                profit += (prices[i] - prices[i-1])
                flag = True
            elif flag:
                if prices[i] < prices[i-1]:
                    flag = False
                else:
                    profit += (prices[i] - prices[i-1])
        return profit

