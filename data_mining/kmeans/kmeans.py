from numpy import *
import math

def loadDataSet(fileName):
	dataMat = []
	fr = open(fileName)
	for line in fr.readlines():
		curLine = line.strip().split('\t')
		fltLine = map(float,curLine)
		dataMat.append(fltLine)
	return dataMat

def pp(aa,bb):
	ss = 0
	a = list(aa)
	b = list(bb)
	for i in range(len(a)):
		ss += (a[i]-b[i])**2
	return math.sqrt(ss)

def distEclud(vecA,vecB):
	return sqrt(sum(power(vecA-vecB,2)))

def randCent(dataSet,k):
	n = shape(dataSet)[1]
	centroids = mat(zeros((k,n)))
	for j in range(n):
		minJ = min(dataSet[:,j])
		rangeJ = float(max(dataSet[:,j]) - minJ)
		centroids[:,j] = minJ + rangeJ * random.rand(k,1)
	return centroids

def kmeans(dataSet,k,distMeas = distEclud,createCent = randCent):
	m = shape(dataSet)[0]
	clusterAssment = mat(zeros((m,2)))
	centroids = createCent(dataSet,k)
	clusterChanged = True
	while clusterChanged:
		clusterChanged = False
		for i in range(m):
			minDist = inf
			minIndex = -1
			for j in range(k):
				distJI = distMeas(centroids[j,:],dataSet[i,:])
				if distJI < minDist:
					minDist = distJI
					minIndex = j
			if clusterAssment[i,0] != minIndex:
				clusterChanged = True
		print centroids
		for cent in range(k):
			ptsInClust = dataSet[nonzero(clusterAssment[:,0].A==cent)[0]]
			centroids[cent,:] = mean(ptsInClust,axis = 0)
	return centroids,clusterAssment

matt =  loadDataSet(r"./testSet2.txt")

print pp(matt[0],matt[1])
print randCent(array(matt),2)
kmeans(array(matt),2)

