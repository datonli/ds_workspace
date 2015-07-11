#include "common.h"

class Solution {
	public:
		    int maxProfit(vector<int>& prices) {
			if(prices.size() < 2)
				return 0;
			
			vector<int>::iterator max_it ;
			vector<int>::iterator min_it ;
			int max = numeric_limits<int>::max();
			int min = numeric_limits<int>::min();
			for(vector<int>::iterator it = prices.begin(); it != prices.end(); ++ it)
			{
				if(*it < min)
				{
					min = *it;
					min_it = it;
				}
				if(*it > max)
				{
					max = *it;
					max_it = it;
				}

			}
			if(max_it > min_it)
				return max-min;
			else
		    	{
				min = numeric_limits<int>::min();
				for(vector<int>::iterator mit = prices.begin(); mit != max_it; ++ mit)
				{
					if(*mit < min)
						min = *mit;
				}
				max = numeric_limits<int>::max();
				for(vector<int>::iterator mat = min_it + 1; mat != prices.end(); ++ mat)
				{
					if(*mat > max)
						max = *mat;

				}

				if(max- *min_it > *max_it - min)
					return max-*min_it;
				else
					return *max_it-min;

			}

		    }

};
