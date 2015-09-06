#include <iostream>
#include <stdio.h>

using namespace std;

// 通过unsigned int 将原来的负数转化为正数，但是在二进制表示中仍然是一样的

int main(){
	int i = -2;
	unsigned int ii = i;
	cout << i << ","  << ii << endl;
	printf("\n%x",i);
	printf("\n%x",ii);


	return 0;
}
