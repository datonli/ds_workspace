#include "mytree.h"

using namespace std;

void initTree(Node *root,int value)
{
	cout << "Init tree..." << endl;
	root = (Node *) malloc(sizeof(Node));
	root->value = value;
	root->lchild = NULL;
	root->rchild = NULL;
	tree = root;
}

void appendTree(Node *&root,int val)
{
	if(root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		root->lchild = NULL;
		root->rchild = NULL;
		root->value = val;
		return ;
	}
	if(root->value > val)
		appendTree(root->lchild,val);
	else
		appendTree(root->rchild,val);
}


void print(Node *root)
{
	if(root == NULL)
		return;
	print(root->lchild);
	cout << root->value << " ";
	print(root->rchild);

}


int main(void)
{
	Node *root ;
	initTree(root,12);

	appendTree(tree,32);
	appendTree(tree,34);
	
	print(tree);
	return 0;
}
