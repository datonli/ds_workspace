'''
@author: Daniel.Lee
'''
from numpy import * 
import matplotlib
import matplotlib.pyplot as plt
from knn import knn

def file2matrix(filename):
    love_dictionary = {'largeDoses':3, 'smallDoses':2, 'didntLike':1}
    fr = open(filename)
    arrayOLines = fr.readlines()
    numberOfLines = len(arrayOLines)
    returnMat = zeros((numberOfLines, 3))
    classLabelVector = []
    index = 0
    for line in arrayOLines:
        listFromLine = line.strip().split('\t')
        returnMat[index, :] = listFromLine[0:3]
        if(listFromLine[-1].isdigit()):
            classLabelVector.append(int(listFromLine[-1]))
        else:
            classLabelVector.append(love_dictionary.get(listFromLine[-1]))
        index += 1
    return returnMat, classLabelVector


#     this is a wrong codes copy from the book!!!
def autoNorm(dataSet):
    minVals = dataSet.min(0)
    maxVals = dataSet.max(0)
    ranges = maxVals - minVals
    normDataSet = zeros(shape(dataSet))
    m = dataSet.shape[0]
    normDataSet = dataSet - tile(1, (m, 1))
    normDataSet = normDataSet / tile(1, (m, 1))
    return normDataSet, ranges, minVals

'''
def autoNorm(dataSet):
    minVals = dataSet.min()
    maxVals = dataSet.max()
    ranges = maxVals - minVals
    m = dataSet.shape[0]
    normDataSet = dataSet - tile(1,(1,m))*minVals
    normDataSet = normDataSet/ranges
    return normDataSet,ranges,minVals
'''
def main():
    datingDataMat, datingLabels = file2matrix('C:\Users\Daniel.Lee\Desktop\machinelearninginaction-master\Ch02\datingTestSet.txt')
    normMat, ranges, minVals = autoNorm(datingDataMat)
#     print datingDataMat
    print datingLabels[0:20]
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(datingDataMat[:, 0], datingDataMat[:, 1], 15.0 * array(datingLabels), 15.0 * array(datingLabels))
    print datingDataMat[:, 0].shape[0]
    print shape(datingDataMat[:, 0])
    print max(datingDataMat[:, 0])
    print datingDataMat[:, 0]
    print normMat
    print datingDataMat.max(0)
#     plt.show()
    
def datingClassTest():
    hoRatio = 0.80
    datingDataMat, datingLabels = file2matrix('C:\Users\Daniel.Lee\Desktop\machinelearninginaction-master\Ch02\datingTestSet.txt')
    normMat, ranges, minVals = autoNorm(datingDataMat)
    m = normMat.shape[0]
    numTestVecs = int(m * hoRatio)
    errorCount = 0.0
    for i in range(numTestVecs):
        classifierResult = knn(normMat[i, :], normMat[numTestVecs:m, :], datingLabels[numTestVecs:m], 3)
        print "the classifier came back with : %d , the real answer is : %d" % (classifierResult, datingLabels[i])
        if classifierResult != datingLabels[i]: errorCount += 1.0
    print "the total error rate is : %d" % ( float(errorCount) / float(numTestVecs))

    '''
    normMat0,ranges,minVals = autoNorm(datingDataMat[:,0])
    normMat1,ranges,minVals = autoNorm(datingDataMat[:,0])
    plt.figure()
    plt.plot(normMat0,normMat1,'ro')
    plt.show()
    '''
if __name__ == '__main__':
#     main()
    datingClassTest()
