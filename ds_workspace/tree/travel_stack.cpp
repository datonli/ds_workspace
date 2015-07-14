#include "mytree.h"
#include <stack>


void preorder(Node * root)
{
	if(root == NULL) return ;
	stack<Node *> s;
	s.push(root);
	while(!s.empty())
	{
		Node *p = s.top();
		s.pop();
		cout << s->val << " " << endl;
		if(p->right) s.push(p->right);
		if(p->left) s.push(p->left);
	}	
}


void postorder(Node *root)
{
	if(root == NULL) return ;
	stack<Node *> s1,s2;
	s1.push(root);
	while(!s1.empty())
	{
		Node *p = s1.top();
		s2.push(s1.pop());
		if(p->left) s1.push(p->left);
		if(p->right) s1.push(p->right);
	}
	while(!s2.empty())
	{
		cout << s2.top()->val << "  " << endl;
		s2.pop();
	}
}


void inorder(Node *root)
{
	if(root == NULL) return;
	stack<Node *> s;
	Node *p = root;
	while(p != NULL || !s.empty())
	{
		if(p != NULL)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->val << " " <<endl;
			p = p->right;
		}
	}


}
