class Solution {
		public:
		    /**
			 *      * @param str: a string
			 *           * @return: a boolean
			 *                */
			    bool isUnique(string &str) {
					map<char,int> m;
					int n = str.size();
					for(int i = 0 ;i < n; i ++){
						if(m[str[i]])
								return false;
						m[str[i]] = 1;
					}
					return true;
		    }
};

