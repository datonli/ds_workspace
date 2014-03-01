#include "../def_pub.h"

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status GetElem(SqList * L,int i,ElemType &e)
{
	if(L->length == 0 || i<1 || i>L->length)
	{
		return ERROR;
	}

	e = L->data[i-1];
	return OK;

}

Status InitList(SqList * L)
{
	L->data[0] = 1;
	for(L->length = 0; L->data[L->length] != 0; L->length ++);
    L->length ++;	
	return OK;	
}

Status ListInsert(SqList * L , int i , ElemType e)
{
    int k;
    if(L->length == MAXSIZE)
        return ERROR;
    if(i<1 || i>L->length+1)
        return ERROR;
    if(i<=L->length)
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1] = L->data[k];

    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListShow(SqList * L)
{
    for(int i = 0; i < L->length; i ++)
        cout << L->data[i] <<endl;
    return OK ;
}

Status ListDelete(SqList * L , int i, ElemType &e)
{
    if(L->length == 0 || i < 1 || i>L->length)
        return ERROR;
    e = L->data[i-1];
    for(int k = i-1; k <= L->length-2; k++)
       L->data[k] = L->data[k+1];
    L->data[L->length-1] = 0;
    L->length --;
    return OK ;
}

int main(int argc,char * argv[])
{
	ElemType e = 0;
	SqList * L = (SqList *) malloc (sizeof(SqList));
	InitList(L);
	cout << L->length << endl;
    GetElem(L,1,e);
    cout << e << endl;
    ListInsert(L,1,4);
    ListInsert(L,1,6);
    ListShow(L);
    ListDelete(L,2,e);
    cout << e << endl;
	return OK;
}

