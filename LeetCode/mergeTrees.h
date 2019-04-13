#include "stdafx.h"

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void addTrees(TreeNode* t1, TreeNode* t2, TreeNode* toot)
{
	if (t1 != NULL)
	{
		toot->val += t1->val;
	}
	 
	if (t2 != NULL)
	{
		toot->val += t2->val;
	}
}

void traversal(TreeNode* t1, TreeNode* t2, TreeNode* root)
{
	TreeNode* t1_temp = NULL;
	TreeNode* t2_temp = NULL;
	TreeNode* root_temp = NULL;
	if(t1 == NULL && t2 == NULL)
		return;

	addTrees(t1, t2, root);
//===============================================
	if ((t1 != NULL && t1->left != NULL) || 
		(t2 != NULL && t2->left != NULL))
	{
		TreeNode* t = new TreeNode(0);
		root->left = t;
	}

	if(t1 != NULL && t1->left != NULL)
		t1_temp = t1->left;
	if(t2 != NULL && t2->left != NULL)
		t2_temp = t2->left;
	if(root != NULL && root->left != NULL)
		root_temp = root->left;
	traversal(t1_temp, t2_temp, root_temp);
//===============================================

	t1_temp = NULL;
	t2_temp = NULL;
	root_temp = NULL;

	if ((t1 != NULL && t1->right != NULL) || 
		(t2 != NULL && t2->right != NULL))
	{
		TreeNode* t = new TreeNode(0);
		root->right = t;
	}

	if(t1 != NULL && t1->right != NULL)
		t1_temp = t1->right;
	if(t2 != NULL && t2->right != NULL)
		t2_temp = t2->right;
	if(root != NULL && root->right != NULL)
		root_temp = root->right;
	traversal(t1_temp, t2_temp, root_temp);
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
	if(t1 == NULL && t2 == NULL)
		return NULL;

	TreeNode* root = new TreeNode(0);
	
	traversal(t1,t2,root);

	return root;
}