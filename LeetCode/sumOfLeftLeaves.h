#include "stdafx.h"

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* root, int& n, bool left)
{
	if (root == NULL)
	{
		return;
	}

	if (root->left != NULL)
	{
		traversal(root->left,n,true);
	}

	if (root->right != NULL)
	{
		traversal(root->right,n,false);
	}

	if (root->left == NULL && root->right == NULL && left == true)
	{
		n +=  root->val;
	}
}


int sumOfLeftLeaves(TreeNode* root) 
{
	int n = 0;
	traversal(root, n, false);

	return n;
}