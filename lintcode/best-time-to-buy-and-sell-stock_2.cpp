#include <iostream>
#include <vector>
using namespace std;

class Solution {
		public:
		    /**
			 *      * @param prices: Given an integer array
			 *           * @return: Maximum profit
			 *                */
				
			    int maxProfit(vector<int> &prices) {
						int n = prices.size();
						if(n<=1) return 0;
						int min_num = prices[0];
						int maxPro = 0;
						for(int i = 1; i < n; i ++){
							maxPro = max(prices[i]-min_num,maxPro);
							if(prices[i] < min_num) min_num = prices[i];
						}
						return maxPro;
				 }

};


int main(){
	Solution sol;
	int a[]  = {3,2,3,1,2};
	vector<int> v(a,a+5);
	cout << sol.maxProfit(v) << endl;
	return 0;
}
