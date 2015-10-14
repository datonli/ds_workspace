class Solution {
		public:
		    /**
			 *      * @param A: An integers array.
			 *           * @return: return any of peek positions.
			 *                */
			    int findPeak(vector<int> A) {
					int n = A.size();
					if(n <=2) return -1;
					for(int i = 1; i <= n-1; i++){
						if(A[i]>A[i-1] && A[i]>A[i+1]) return i+1;
					}
					return -1;
		    }
};
