/*
 * 待解决问题：
 * 对一个指向结构体的指针p来说，p = p+1是代表什么意思，是指跳过整个元素呢还是什么？？？ 2014-3-2
 * */


#include "../def_pub.h"


typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node,* LinkList;

Status ListAdd(LinkList L,ElemType e);

Status ListInit(LinkList L)
{
    L->data = 0;
    L->next = (LinkList) malloc (sizeof(Node));
    L->next->data = 3;
    L->data ++;
    L->next->next = NULL;
    return OK ;
}

Status ListInsert(LinkList L,int i , ElemType e)
{
    LinkList p = L;
    p = p+i;
    LinkList newNode = (LinkList) malloc (sizeof(Node));
    newNode->data = e;
    if(p->next != NULL)
    {
        p = p-1;
        newNode->next = p->next;
        p->next = newNode;
        L->data ++;
    }
    else
    {
        ListAdd(L,e);
    }
    return OK;
}

Status ListAdd(LinkList L,ElemType e)
{
    LinkList p = L;
    for(;p->next != NULL;p = p->next);
    p->next = (LinkList)malloc(sizeof(Node));
    p->next->data = e;
    p->next->next = NULL;
    L->data++;
    return OK;
}

Status ListDisplay(LinkList L)
{
    LinkList p = L;
    for(;p->next != NULL;p = p->next)
        cout << p->data << endl;
    cout << p->data << endl;
    return OK;
}

Status ListDelete (LinkList L,int i,ElemType &e )
{
    LinkList p = L;
    for(;i != 1; --i)
    {
        if(p -> next != NULL)
        {
            p = p->next;
        }
        else
        {

            cout << "delete ER" << endl;
            return ERROR;
        }
    }
    e = p -> next -> data;
    LinkList q = p -> next;
    p -> next = p ->next -> next;
    free(q);
    cout << "delete OK" << endl;
    return OK;
}

Status ListFree(LinkList L)
{
    LinkList p = L;
    if(p != NULL)
    {
        while(!p)
        {
            LinkList q = p;
            p = p->next;
            free(q);
        }
    }
    return OK;
}

int main(int argc , char * argv[])
{
    LinkList L = (LinkList) malloc(sizeof(Node));
    ListInit(L);
    ListInsert(L,1,9);
    ListAdd(L,7);

    ListDisplay(L);
    ElemType e;
    ListDelete(L,2,e);
    cout << "the e is : " << e << endl;
    ListDisplay(L);
    ListFree(L);
}
