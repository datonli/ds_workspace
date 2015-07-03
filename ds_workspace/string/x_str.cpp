#include <iostream>

using namespace std;

int j;


int main()
{
	string s("abcdefg");
	for(char &ss : s)
	{
		ss = 'x';	
	}	
	cout << s <<endl;
	string d;
	cout << d[0] << endl;
	int i;
	cout << i << " " << j << endl;
	return 1;
}
