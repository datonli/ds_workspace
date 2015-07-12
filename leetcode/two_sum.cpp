


class Solution {
	public:
		    vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int,int> hash;
			vector<int> result;
			for(int i =0; i < nums.size(); i++)
			{
				int num_find = target - nums[i];
				if(hash.find(num_find) != hash.end())
				{
					result.push_back(hash[num_find] + 1);
					result.push_back(i + 1);
					return result;
				}



				hash[nums[i]] = i;
			}	
			
			return result;

			        }
};
