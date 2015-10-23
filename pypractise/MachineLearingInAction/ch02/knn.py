'''
@author: Daniel.Lee
'''

from numpy import *
import operator
import matplotlib.pyplot as mpl

def createDataSet():
    group = [[3, 104], [2, 100], [1, 81], [101, 10], [99, 5], [98, 2]]
    group = array(group)
    labels = ['Love', 'Love', 'Love', 'Action', 'Action', 'Action']
    return group, labels

def knn(classifyArray, dataSet, labels, k):
    dataSetSize = dataSet.shape[0]
    diffMat = tile(classifyArray, (dataSetSize, 1)) - dataSet
    sqDiffMat = diffMat ** 2
    distances = sqDiffMat.sum(axis=1) ** 0.5
    sortedDistindicies = distances.argsort()
    classCount = {}
    for i in  range(k):
        voteIlabel = labels[sortedDistindicies[i]]
        classCount[voteIlabel] = classCount.get(voteIlabel, 0) + 1
        sortedClassCount = sorted(classCount.iteritems(),key = operator.itemgetter(1), reverse = True)
        return sortedClassCount[0][0]

def main():
    group, labels = createDataSet()
    mpl.figure()
    x = []
    y = []
#     for i in range(group.shape[0]):
#         gx,gy = group[i]
#         x.append(gx)
#         y.append(gy)
    
    newPoint = [18,90]
    print knn(newPoint,group,labels,3)
    for gx, gy in group:
        x.append(gx)
        y.append(gy)
    mpl.plot(x, y, 'bo')
    mpl.plot(newPoint[0],newPoint[1],'ro')
    mpl.xlabel('Action')
    mpl.ylabel('Love')
    mpl.show()
    
if __name__ == '__main__':
    main()
