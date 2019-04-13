#include "stdafx.h"
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool traversal(TreeNode* p, TreeNode* q)
{
	if (p != NULL && q != NULL)
	{
		if (p->val == q->val)
		{
			return traversal(p->left, q->left) && traversal(p->right, q->right);
		}
		else
		{
			return false;
		}
	}
	else if(p == NULL && q == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool isSameTree(/*TreeNode* p, TreeNode* q*/)
{
	TreeNode *p = new TreeNode(1);
	p->left = new TreeNode(1);
	TreeNode *q = new TreeNode(1);
	q->left = new TreeNode(1);

	bool b = traversal(p,q);
	return b;
}


bool traversalSymmetric(TreeNode* p, TreeNode* q)
{
	if (p != NULL && q != NULL)
	{
		if (p->val == q->val)
		{
			return traversal(p->left, q->right) && traversal(p->right, q->left);
		}
		else
		{
			return false;
		}
	}
	else if(p == NULL && q == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool isSymmetric(TreeNode* root) 
{
	bool b = false;
	if(root == NULL)
		return true;

	if(root && root->left== NULL && root->right== NULL)
		return true;

	if(root && root->left && root->right)
		b = traversalSymmetric(root->left,root->right);
	return b;    
}