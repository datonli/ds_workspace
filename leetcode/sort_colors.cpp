#include "common.h"



class Solution {
	public:
		    void sortColors(vector<int>& nums) {
			int red = 0;
			int white = 0;
			int blue = 0;
			for(int n : nums)
			{
				switch(n)
				{
					case 0:
						red ++;
						break;
					case 1:
						white ++;
						break;
					case 2:
						blue ++;
						break;
				}
			}
			fill(nums.begin(),nums.begin()+red,0);
			fill(nums.begin()+red,nums.begin()+red+white,1);
			fill(nums.begin()+red+white,nums.end(),2);
			        }
};
