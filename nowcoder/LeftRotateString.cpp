#include <iostream>
#include <string>
using namespace std;


class Solution {
		public:
		    string LeftRotateString(string str, int n) {
				if(str.length() < n) return "";
				string substr = str.substr(n);
				return substr.append(str.substr(0,n));
							    }
};

int main(){
	Solution sol ;
	string s("abcXYZdef");
	cout << sol.LeftRotateString(s,3) << endl;
		return 0;
}
