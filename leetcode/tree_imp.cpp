#include "tree_def.h"


void addNode(TreeNode *&root,int &ind)
{
	if(ind == sizeof(val)/sizeof(val[0]))
		return;
	if(val[ind] == 0)
	{
		root = NULL;
	}
	else
	{
		root = new TreeNode(val[ind]);
		cout << val[ind] << endl;
		addNode(root->left,++ind);
		addNode(root->right,++ind);	
	}
}

void addNodeAVL(TreeNode *&root,int value)
{
	if(root == NULL)
	{
		root = new TreeNode(value);
		cout << value << endl;
		return;
	}
	else
	{
		if(value < root->val)
			addNodeAVL(root->left,value);
		else
			addNodeAVL(root->right,value);
	}

}

void print(TreeNode *&root)
{
	if(root != NULL)
	{
		cout << root->val << " ";
		print(root->left);
		print(root->right);
	}
}

int GetTreeDepth(TreeNode *root)
{
	if(root == NULL)
		return 0;
	int leftDepth = GetTreeDepth(root->left);
	int rightDepth = GetTreeDepth(root->right);
	return leftDepth>rightDepth?(leftDepth+1):(rightDepth+1);
}

int getNodeNum(TreeNode *root)
{
	if(root == NULL)
		return 0;
	int leftNum = getNodeNum(root->left);
	int rightNum = getNodeNum(root->right);
	return (leftNum + rightNum + 1);
}


int main(void)
{
	TreeNode *root = NULL;
	int ind = 0;
	//addNode(root,ind);
	for(; ind < sizeof(val)/sizeof(val[0]); ++ind )
		addNodeAVL(root,val[ind]);
	print(root);
	cout << endl;
	int depth = GetTreeDepth(root) ;
	cout << depth << endl;
	cout << "node num is : " << getNodeNum(root) << endl;
	return 0;		
}
