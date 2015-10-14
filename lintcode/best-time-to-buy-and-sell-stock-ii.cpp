#include <iostream>
#include <vector>
using namespace std;


class Solution {
		public:
		    /**
			 *      * @param prices: Given an integer array
			 *           * @return: Maximum profit
			 *                */

				int cal(vector<int> &prices,int n){
							int A = 0;
							if(n<=0) return 0;
							else A = prices[n] - prices[n-1];
							return A>0?(cal(prices,n-1)+A):cal(prices,n-1);
						}


			    int maxProfit(vector<int> &prices) {
							int n = prices.size();
							return cal(prices,n-1);
				    }
};

int main(){
	Solution sol;
	vector<int> v ;
	v.push_back(3);
	v.push_back(2);
	v.push_back(6);
	v.push_back(5);
	v.push_back(0);
	v.push_back(3);
	cout << sol.maxProfit(v) << endl;
	return 0;
}

