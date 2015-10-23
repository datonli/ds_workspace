__author__ = 'Daniel.Lee'

class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        num = len(points)
        if num < 2:
            return num
        maxP = 2
        for i in range(0,num):
            pi = points[i]
            duplicate = 0
            d = {}
            for j in range(i+1,num):
                pj = points[j]
                if pi.x == pj.x and pi.y == pj.y :
                    duplicate += 1
                else:
                    if (pj.x - pi.x) == 0:
                        key = 0
                    else:
                        key = float(pj.y - pi.y)/(pj.x - pi.x)
                    if key not in d.keys():
                        d[key] = 2
                    else:
                        d[key] += 1

            if d.values() != []:
                maxP = max(maxP,max(d.values()) + duplicate)
            else:
                return max(maxP,duplicate + 1)
        return maxP

if __name__=='__main__':
    # [(3,10),(0,2),(0,2),(3,10)]
    points=[Point(3,10),Point(0,2),Point(0,2),Point(3,10)]
    print(Solution().maxPoints(points))


