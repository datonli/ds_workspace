#include <iostream>
using namespace std;

class Solution {
		public:
		    int Add(int num1, int num2)
			    {
					int n1,n2;
					do{
						n1 = num1^num2;
						n2 = (num1&num2)<<1;
						num1 = n1;
						num2 = n2;
					}while(n2);
				return n1;
			    }
};


int main(){
	Solution sol ;
	cout << sol.Add(3,5) << endl;
	return 0;
}
