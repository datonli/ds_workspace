#include <vector>
#include <string>
#include <iostream>

using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		vector<char> v;
		cin >> s;
		for(int i = 0; i < s.size(); i ++){
			if(s.at(i) == '@') v.clear();
			else if(s.at(i) == '#') v.pop_back();
			else v.push_back(s.at(i));
		}
		for(int i = 0; i < v.size(); i ++) {
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}
