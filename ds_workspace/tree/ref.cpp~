#include <iostream>

using namespace std;

void p_test(int *p)
{
	p = (int *)12;
}

void r_test(int &p)
{
	p = (int *)12;
}


int main(void)
{
	int i = 10;
	cout << "&i = " << &i <<endl;
	p_test(&i);
	cout << "&i = " << &i <<endl;
	int j = &i;
	cout << "&j = " << &j <<endl;
	r_test(&j);
	cout << "&i = " << &i <<endl;
	return 0;
}
