#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        int tab[2*26];
        int c = 0;
		for(int i = 0 ; i < 2 * 26; i ++) tab[i] = -1;
        for(int i = 0; i < str.size(); i ++){
            c = str.at(i) - 65;
            if(tab[c] == -1 ) tab[c] = i;
            else tab[c] = -2;
        }
        int ind = -1,min = str.size();
        for(int i = 0; i< 2*26; i++){
			cout << tab[i] << "," ;
            if(tab[i] >= 0){
                if(tab[i] < min){
                    min = tab[i];
                    ind = i;
                }
            }
        }
		
        if(ind == -1)return -1;
        else
            return tab[ind];
    }
};


int main(){
	Solution sol ;
	string str("google");
	cout << sol.FirstNotRepeatingChar(str) << endl;
	return 0;
}
