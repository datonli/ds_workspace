#include <iostream>
#include <string>
using namespace std;


class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        int cnt = 0;
        int i = 0;
        while(i < length){
            if(iniString.at(i) == ' ') ++cnt;
            ++i;
        }           
        int interval = cnt*2;
        for(i = length - 1; i >= 0; -- i){
            if(iniString[i] == ' '){
				cout << interval << endl;
                iniString[i + interval] = '0';
                iniString[i + --interval] = '2';
                iniString[i + --interval]= '%';
				cout << interval << endl;
            }else{
                iniString[i + interval] = iniString[i];
            }
        }
        return iniString;
    }
};

int main(){
	Replacement rep;
	string s = "Hello world grece    ";
	cout << rep.replaceSpace(s,17) << endl;
	return 0;
}
