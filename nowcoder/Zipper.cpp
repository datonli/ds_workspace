#include <iostream>
#include <string>
using namespace std;

class Zipper {
public:
    string zipString(string iniString) {
        
        string s ;
        int cnt = 0;
        for(int i = 0; i < iniString.length(); ++i){
            cnt = 1;
           while(i + 1 < iniString.size() && iniString[i] == iniString[i+1]) {
               cnt ++;
               i++;
           }
                s += iniString[i];
				s += to_string(cnt);
        }
        if(iniString.size() > s.size()) return s;
        return iniString;
    }
};


int main(){
	Zipper z ;
	string s("jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF");
	cout << z.zipString(s) << endl;
	return 0;
}
