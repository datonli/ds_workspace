
class Solution {
	public:
		    vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> arr ;
			map<int,int> matmap;
			int flag = 1;
			int i = 0,j = 0;
			int len = matrix.size();
			if(len == 1)
			{
				arr.push_back(matrix[0][0]);
				return arr;
			}
			if(len == 2)
			{
				arr.push_back(matrix[0][0]);
				arr.push_back(matrix[0][1]);
				arr.push_back(matrix[1][1]);
				arr.push_back(matrix[1][0]);
				return arr;

			}
			int last_i = 0,last_j = 0;
			if(len%2 == 0)
			{
				last_j = (len-1)/2;		
				last_i = last_j * 2;
			}
			else
			{
				last_j = len/2;
				last_i = len/2;
			}
			while(flag)
			{
				int arr_len = arr.size();
				while(matmap.insert(i,j).second)
				{
					arr.push_back(matrix[i][j]);
					switch(flag%4)
					{
						case 1:
							j++;
							break;
						case 2:
							i++;
							break;
						case 3:
							j--;
							break;
						case 0:
							i--;
							break;
					}
					if(i == len) 
					{
						i--;
						break;
					}
					if(i == -1) 
					{
						i ++;
						break;
					}
					if(j == len) 
					{
						j--;
						break;
					}
					if(i == -1) 
					{
						i++;
						break;
					}
				}	
				flag++;
				if(arr_len == arr.size())
					flag = 0;
			}
			return arr;
			        }
};
