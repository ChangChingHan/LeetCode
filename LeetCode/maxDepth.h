#include "stdafx.h"

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int searchDepth(int d, TreeNode* root)
{
	int result_l = d;
	int result_r = d;

	if (root == NULL)
	{
		return d;
	}

	TreeNode* t = NULL;
	if (root != NULL && root->left != NULL)
	{
		t = root->left;
		result_l = searchDepth(d+1,t);
		if(d > result_l)
			result_l = d;
	}
	t = NULL;
	if (root != NULL && root->right != NULL)
	{
		t = root->right;
		result_r = searchDepth(d+1,t);
		if(d > result_r)
			result_r = d;
	}

	return max(result_l, result_r);
}

int maxDepth() 
{
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);

	if (root == NULL)
	{
		return 0;
	}
	return searchDepth(1,root);
}