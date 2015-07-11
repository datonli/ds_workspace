class Solution {
	public:
		    int maxProfit(vector<int>& prices) {
			long sum = 0;
			int tmp = 0;
			if(prices.size() < 2)
				return sum;
			for(vector<int>::iterator it = prices.begin(); it != prices.end() - 1; ++ it)
    			{
				if((tmp = *(it+1) - *it) > 0)
				{
					sum += tmp;
				}		
			}			
			return sum;
		   }
};
