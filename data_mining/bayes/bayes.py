

def loadDataSet(fileName):
	dataMat = []
	fr = open(fileName)
	for line in fr.readlines():
		curLine = line.strip().split('\t')
		fltLine = map(int,curLine)
		dataMat.append(fltLine)
	return dataMat

def statRe(dataMat):
	sum = 0.0
	re2 = []
	for d in dataMat:
		if d[2] == 2:
			sum += 1
			re2.append(d)
	return re2,sum,sum/len(dataMat)

def statF(dataMat):
	re2dict = {}
	for d in dataMat:
		if d[0] not in re2dict.keys():
			re2dict[d[0]] = 1
		else:
			re2dict[d[0]] += 1
	pp = []
	length = len(dataMat)+0.0
	for i in range(1,11):
		pp.append(re2dict[i]/length)
	return pp

def stat(dataMat):
	c99 = 0
	c99re2 = 0
	for d in dataMat:
		if d[0] == 9 and d[1] == 9:
			c99 += 1
			if d[2] == 2:
				c99re2 += 1
	return (c99re2+0.0)/c99


def bayes(dataMat,pre2):
	re2fc9 = 0
	re2cc9 = 0
	re2 = 0
	re1fc9 = 0
	re1cc9 = 0
	re1 = 0
	cc9 = 0
	fc9 = 0
	re2 = 0
	sre1 = 0
	sre2 = 0
	fc9cc9 = 0
	for d in dataMat:
		if d[0] == 9:
			fc9 += 1
		if d[1] == 9:
			cc9 += 1
		if d[0] == 9 and d[1] == 9:
			fc9cc9 += 1

		if d[2] == 1:
			sre1 += 1
			if d[0] == 9:
				re1fc9 += 1
			if d[1] == 9:
				re1cc9 += 1
			if d[0] == 9 and d[1] == 9:
				re1 += 1
		else:
			sre2 += 1
			if d[0] == 9:
				re2fc9 += 1
			if d[1] == 9:
				re2cc9 += 1
			if d[0] == 9 and d[1] == 9:
				re2 += 1
	print pre2,fc9,cc9,re2,re2fc9,re2cc9,re1fc9,re1cc9
	p2 = pre2*re2fc9*re2cc9/(re2*re2+0.0)
	p1 = (1-pre2)*re1cc9*re1fc9/(0.0+re1*re1)
	print p2,p1,p2/(p1+p2)
	print re1fc9,re1cc9,re1,re2fc9,re2cc9,re2
	print (re1fc9+0.0)/sre1,(re1cc9+0.0)/sre1,(re2fc9+0.0)/sre2,(re2cc9+0.0)/sre2
	return (pre2*re2fc9*re2cc9/(sre2*sre2+0.0))/(pre2*re2fc9*re2cc9/(sre2*sre2+0.0)+(1-pre2)*re1cc9*re1fc9/(0.0+sre1*sre1))



dataSet = loadDataSet(r'./public.txt')
re2,sum,result = statRe(dataSet)
print result
print statF(re2)
print stat(dataSet)
print bayes(dataSet,result)
