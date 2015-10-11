#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
	int n,m;
	multimap<int,int> mp;
	set<int> s ;
	while(cin>>n>>m){
		int a,b;
		int cm = m;
		if(m == n && n == 0) break;
		else{
			while(m--){
				cin >> a >> b;		
				mp.insert(pair<int,int>(a,b));
			}
			s.insert(1);
			for(int i = 0; i < cm; i ++)
				for(map<int,int>::iterator it = mp.begin(); it!=mp.end(); ++it)
				{
					if(s.find(it->first) != s.end())  s.insert(it->second);
					if(s.find(it->second) != s.end())  s.insert(it->first);
				}
		}
		cout << s.size()-1 << endl;
		s.clear();
		mp.clear();
	}
	return 0;
}
