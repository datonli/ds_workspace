#include <iostream>

using namespace std;

int main()
{
	string s("adb,de:ds");
	string d;
	for (auto ss: s)
	{
		if(!ispunct(ss))
			d += ss;
	}
	cout << d << endl;
	return 1;
}
