#include "../def_pub.h"

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status InitTree(BiTree T,ElemType e)
{
    T->data = e;
    T->lchild = T->rchild = NULL;
    return OK;
}

Status DisplayTree(BiTree T)
{
    BiTree p = T;
    if(p == NULL)
    {
        return ERROR;
    }
    cout << p->data << endl;
    DisplayTree(p->lchild);
    DisplayTree(p->rchild);
    return OK;
}

Status AddNodeTree(BiTree T,ElemType e)
{
    BiTree p = T;
    if(p->data == '#')
        return ERROR;
    if(p->lchild == NULL)
    {
        p->lchild = (BiTree)malloc (sizeof(struct BiTNode));
        InitTree(p->lchild,e);
    }
    else if((p->lchild != NULL) && (p->rchild == NULL))
    {
        p->rchild = (BiTree)malloc (sizeof(struct BiTNode));
        InitTree(p->rchild,e);
    }
    else if((p->lchild != NULL) && (p->rchild != NULL))
    {
        AddNodeTree(p->lchild,e);
        AddNodeTree(p->rchild,e);
    }


    return OK;
}



int main(int argc,char * argv[])
{
    BiTree T = (BiTree) malloc (sizeof(struct BiTNode));
    InitTree(T,2);
    AddNodeTree(T,3);
    AddNodeTree(T,'#');
    DisplayTree(T);
    return OK;
}
