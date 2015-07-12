#include "common.h"

class Solution {
	public:
		    int removeDuplicates(vector<int>& nums) {
			if(nums.size() < 2)
				return nums.size();
			int len = 0;
			int temp = nums[1];
			for(int i = 2; i < nums.size(); )
    			{
				if(nums[i] == nums[i-2])
					i++;
				else
				{
					nums[++len] = temp;
					temp = nums[i++];
				}		
				
			}	
			nums[++len] = temp;
			return ++len;			
			        }
};


int main()
{
	Solution *sol;
	vector<int> nums{3,3,3,3,3,4,4,6,9};
	cout << sol->removeDuplicates(nums) << endl;
	for (auto n:nums)
		cout <<  n  << " ,";
	cout << endl;
	return 0;

}
