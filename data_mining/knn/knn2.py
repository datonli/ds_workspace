#3,5,16,2
#0.19,0.04,0.06,0.22,0.11,A
#0.28,0.42,0.38,0.39,0.44,B
#0.71,0.61,0.54,0.52,0.54,C
#0.98,0.82,0.92,0.98,0.97,D
#0.05,0.03,0.15,0.01,0.11,A
#0.33,0.29,0.33,0.47,0.27,B
#0.72,0.52,0.61,0.71,0.68,C
#0.78,0.86,0.91,1.0,0.76,D
#0.01,0.17,0.14,0.15,0.2,A
#0.44,0.36,0.32,0.32,0.35,B
#0.67,0.65,0.57,0.58,0.52,C
#0.87,0.92,0.8,0.83,0.77,D
#0.01,0.11,0.14,0.12,0.07,A
#0.33,0.43,0.43,0.45,0.38,B
#0.57,0.54,0.75,0.7,0.64,C
#0.9,0.94,0.83,0.96,0.77,D
#0.29,0.29,0.42,0.36,0.27
#0.56,0.67,0.71,0.66,0.7
import operator
import math

def createDataSet():
	group = [[0.19,0.04,0.06,0.22,0.11],[0.28,0.42,0.38,0.39,0.44],[0.71,0.61,0.54,0.52,0.54],[0.98,0.82,0.92,0.98,0.97],[0.05,0.03,0.15,0.01,0.11],[0.33,0.29,0.33,0.47,0.27],[0.72,0.52,0.61,0.71,0.68],[0.78,0.86,0.91,1.0,0.76],[0.01,0.17,0.14,0.15,0.2],[0.44,0.36,0.32,0.32,0.35],[0.57,0.54,0.75,0.7,0.64]]
	labels = ['A','B','C','D','A','B','C','D','A','B','C']
	return group,labels

def getSqrt(x,d):
	n = len(x)
	sum = 0
	for i in range(n):
		sum += (x[i] - d[i])**2
	return math.sqrt(sum)


def getDis(inX,dataSet):
	dis = []
	for d in dataSet:
		dis.append(getSqrt(inX,d))
	return dis

def knn(inX,dataSet,labels,k):
	dataSetSize = len(dataSet)
	distances = getDis(inX,dataSet) 
	print distances
	sortedDis = sorted(distances)
	print sortedDis
	sortedDistIndicies = []
	for i in range(len(sortedDis)):
		cnt = 0
		while cnt < len(sortedDis):
			if distances[cnt] == sortedDis[i]:
				sortedDistIndicies.append(cnt)
				break
			else:
				cnt += 1
	print sortedDistIndicies
	classCount = {}
	for i in range(k):
		voteIlabel = labels[sortedDistIndicies[i]]
		print voteIlabel
		classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1
	print classCount
	sortedClassCount = sorted(classCount.iteritems(),key = operator.itemgetter(1),reverse = True)
	print sortedClassCount
	num = sortedClassCount[0][1]
	result = []
	result.append(sortedClassCount[0][0])
	for i in range(1,len(sortedClassCount)):
		if num == sortedClassCount[i][1]:
			result.append(sortedClassCount[i][0])
	result.sort()
	result = "".join(result)
	return result

group,labels = createDataSet()
print knn([0.29,0.29,0.42,0.36,0.27],group,labels,5)


