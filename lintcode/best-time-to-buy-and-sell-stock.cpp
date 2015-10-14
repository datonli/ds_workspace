#include <iostream>
#include <vector>
using namespace std;

class Solution {
		public:
		    /**
			 *      * @param prices: Given an integer array
			 *           * @return: Maximum profit
			 *                */
				
				int find_min(vector<int> &prices,int start,int end){
					int min_num = prices[start];
					for(int i = start; i < end; i ++)
							if(min_num > prices[i]) min_num = prices[i];
					return min_num;
				}

				int mp(vector<int> &prices,int n){
					if(n<=1) return 0;
					return std::max(prices[n-1] - find_min(prices,0,n-1),mp(prices,n-1));
					}

			    int maxProfit(vector<int> &prices) {
			     	return mp(prices,prices.size());
				 }

};


int main(){
	Solution sol;
	int a[]  = {3,2,3,1,2};
	vector<int> v(a,a+5);
	cout << sol.maxProfit(v) << endl;
	return 0;
}
