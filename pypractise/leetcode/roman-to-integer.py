__author__ = 'Daniel.Lee'

import re

class Solution:
    # @return an integer
    def romanToInt(self, s):
        sum = 0
        for i in range(0,len(s)):
            if s[i] == 'I': sum += 1
            elif s[i] == 'V': sum += 5
            elif s[i] == 'X': sum += 10
            elif s[i] == 'L': sum += 50
            elif s[i] == 'C': sum += 100
            elif s[i] == 'D': sum += 500
            elif s[i] == 'M': sum += 1000

        if s.find('IV') != -1: sum -= 2
        if s.find('IX') != -1: sum -= 2
        if s.find('XL') != -1: sum -= 20
        if s.find('XC') != -1: sum -= 20
        if s.find('CD') != -1: sum -= 200
        if s.find('CM') != -1: sum -= 200
        return sum