#include "common.h"

class Solution {
	public:
		    void rotate(vector<vector<int>>& matrix) {
			vector<vector<int>> mat;
			
			int N = matrix.size();
			for(int i = 0; i < N;i ++)
			{
				vector<int> a(N,0);
				mat.push_back(a);
			}			
			
			for(int i = 0; i < N; i++)
			{
				for(int j = 0 ; j < N ; j ++)
				{
					mat[j][N-1-i] = matrix[i][j];
				}
			}
			return mat;
			        }
};
