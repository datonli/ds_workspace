#include <iostream>


using namespace std;


int val[] = {3,2,0,0,1,5,8,0,9};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

void addNode(TreeNode *&root,int &ind);
void addNodeAVL(TreeNode *&root,int ind);
int GetTreeDepth(TreeNode *root);
int getNodeNum(TreeNode *root);
