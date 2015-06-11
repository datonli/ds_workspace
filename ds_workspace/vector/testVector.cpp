#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> v;
	v.push_back(12);
	v.push_back(1);
	for(Vector<int>::iterator itr = v.begin(); itr != v.end(); itr ++)
		cout << *itr << endl;
	return 1;
}
