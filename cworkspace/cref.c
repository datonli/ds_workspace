#include <stdio.h>

#define PCHAR char*
//typedef (char *) PCHAR




typedef struct LNode{
	char c;
	int n;
}LNode,* LinkList;

int f2f(PCHAR &ch)
{
	ch[0] = 'e';
	return 0;
}

int func (LinkList &L)
{
	printf("c = %c,n = %d\n",L->c,L->n);
	L->c = 'F';
	return -1;
}


int main()
{
	char ych[] = "fd";
	PCHAR ch = ych;
	f2f(ch);
	printf("ch is %s\n",ch);
	LNode l = {'a',5};
	LinkList L = &l;
	(*L).c = 'H';
	L->n = 2;	
	func(L);
	printf("c = %c,n = %d\n",L->c,L->n);
	return 1;
}

