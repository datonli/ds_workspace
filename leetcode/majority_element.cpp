#include "common.h"

class Solution {
	public:
		    int majorityElement(vector<int>& nums) {
			map<int,int> mapint;
			map<int,int>::iterator ind;
			for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
			{
				if((ind = mapint.find(*it)) == mapint.end())
					mapint[*it] = 1;
				else
					mapint[*it] += 1 ;

			}		
			
			int max = 0;
			int count = 0;
			for(ind = mapint.begin(); ind != mapint.end(); ++ind)
			{
				cout << ind->first << "  " << ind->second << endl;
				if(ind->second > count)
				{
					count = ind->second;
					max = ind->first;
			
				}
			}
			return max;

			        }
};


int main()
{
	Solution *sol ;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	cout << sol->majorityElement(nums) << endl;
	return 0;
}
