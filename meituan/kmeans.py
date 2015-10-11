class Solution:
	def createCent(self,xy,k):
		xyMin = min(xy)
		xyMax = max(xy)
		xyRange = xyMax - xyMin
		cxy = []
		for i in range(2*k):
			cxy.append(xyMin + random.rand(0,1)*xyRange)
		return cxy
	
	def distEclud(pA,pB):
		return sqrt(sum(power(pA[0]-pB[0],2),power(pA[1]-pB[1])))

    def k_means_clustering(self, n, xy, k, cxy):
		flag = True
		arrflag = [-1 for i in range(n)]
		cxy = createCent(xy,k)
		while flag:
			flag = False
			for i in range(n):
				minDis = 0
				minInd = -1
				for j in range(k):
					dis = distEclud(xy[i*2:i*2+2],cxy[j*2:j*2+2])
					if dis < minDis:
						minDis = dis
						minInd = j
				if arrflag[i] != j:
					arrflag[i] = j
					flag = True
			#caculate cent for update
			for i in range(k):
				ind  = i
				for j in range(k):
					x = 0
					y = 0
					cnt = 0
					for m in range(n):
						if j == arrflag[m]:
							cnt += 1
							x += xy[m*2]
							y += xy[m*2+1]
					x = x/cnt
					y = y/cnt
					cxy[2*i] = x
					cxy[2*i+1] = y
		#end
