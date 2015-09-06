#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    int binaryFind(vector<int> &data, int begin, int end ,int k){
		int ind = -1;
		if(begin >= end) return -1;
		int mid = (end + begin) / 2;
		if(k == data[mid]) return mid;
		if((ind = binaryFind(data,begin,mid,k)) != -1) return ind;
		if((ind = binaryFind(data,mid+1,end,k)) != -1) return ind;
		return -1;
    }
    
public:
    int GetNumberOfK(vector<int> data ,int k) {
			int ind = binaryFind(data,0,data.size(),k);
			if(ind == -1) return 0;
			int pos = ind;
			int cnt = 1;
			while(--pos >= 0 && k == data[pos]) ++cnt;
			while(++ind < data.size() && k == data[ind]) ++cnt;
			return cnt;
    }
    
    
};


int main(){
	Solution sol ;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << sol.GetNumberOfK(v,3) << endl;
	return 0;
}
