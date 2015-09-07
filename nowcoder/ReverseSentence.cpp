#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

public:
    string ReverseSentence(string str) {
        reverse(str.begin(),str.end());
        int ind = 0;
        int pre = 0;
        while(ind < str.size()){
			cout << str << endl;
            pre = ind;
            if((ind = str.find_first_of(' ',pre)) == string::npos) {
            	reverse(str.begin()+pre,str.end());
				break;
			}
            reverse(str.begin()+pre,str.begin()+ind);
            ind = ind + 1;
        }
        return str;
    }
};


int main(){
	Solution sol ;
	string str("student. a am I");
	cout << sol.ReverseSentence(str) << endl;
	return 0;
}
