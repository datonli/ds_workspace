#include <stdio.h>

int main()
{
	int * m,n;
	int a = 1;
	m =&a;
	printf("n = %d \n ",n);
	n =&a;
	//n = a;
	//printf("n = %d, m = %d, * m = %d \n",n,m,* m );
	printf("*m = %d,n = %d,*n = %d\n",*m,n,*n);
	return 1;
}
