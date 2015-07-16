#include "common.h"

int main()
{
	map<int,int> mymap;
	mymap.insert(pair<int,int>(1,1));
	if(mymap.insert(pair<int,int>(1,1)).second == false) 
		cout << "insert fail" << endl;
	return 0;
}
