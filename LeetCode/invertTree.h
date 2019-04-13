#include "stdafx.h"

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* root)
{
	if(root == NULL)
		return;
	
	TreeNode* t = root->left;
	root->left = root->right;
	root->right = t;

	if (root->left != NULL)
	{
		traversal(root->left);
	}

	if (root->right != NULL)
	{
		traversal(root->right);
	}
}

TreeNode* prepareTreeData()
{
	TreeNode *p = new TreeNode(0);
	p->left = new TreeNode(4);
	p->right = new TreeNode(3);

	p->left->left = new TreeNode(4);
	p->left->right = new TreeNode(3);

	p->right->left = new TreeNode(1);
	//p->right->right = new TreeNode(5);

	return p ;
}

bool compareTree(TreeNode* root)
{
	if (root->left != NULL && root->right != NULL)
	{
		if (root->left->val < root->right->val)
		{
			return false;
		}
	}

	bool left = true;
	bool right = true;

	if (root && root->left)
	{
		left = compareTree(root->left);
	}

	if (root && root->left)
	{
		right = compareTree(root->right);
	}

	if (left && right)
	{
		return true;
	}
	return false;
}

TreeNode* getTreeNode(TreeNode* root, int n)
{
	if(root == NULL)
		return NULL;
	if (root->val == n)
	{
		return root;
	}

	TreeNode* p = getTreeNode(root->left,n);

	if(p == NULL)
		p = getTreeNode(root->right,n);

	return p;
}

TreeNode* invertTree(TreeNode* root) 
{

	traversal(root);


	return root;
}