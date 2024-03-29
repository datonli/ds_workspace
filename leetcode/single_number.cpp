#include <iostream>
#include <vector>
using namespace std;

class Solution{
	
public:
	int singleNumber(vector<int>& nums){
		int sum = 0;
		for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			sum ^= *it;
		}
		return sum;
	}

};


int main(void)
{
	Solution *sol = new Solution();
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(8);
	cout << sol->singleNumber(nums) << endl;
	delete [] sol;
	return 0;
}
