#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(5);
	v.push_back(3);
	v.push_back(5);
	v.push_back(10);
	v.push_back(20);
	v.push_back(1);
	sort(v.begin(),v.end());
	for(int i = 0; i < v.size(); i ++) cout << v[i]<< " ";
	cout << endl;
	vector<int>::iterator it = unique(v.begin(),v.end());
	//for(; it != v.end(); it++) cout << *it << " ";
	//cout << endl;
	//it = unique(v.begin(),v.end());
	v.erase(it,v.end());
	for(int i = 0; i < v.size(); i ++) cout << v[i]<< " ";
	cout << endl;
	return 0;
}
