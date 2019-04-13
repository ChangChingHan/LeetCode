#include "stdafx.h"

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(vector<int>& v, TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	v.push_back(root->val);

	if (root->left != NULL)
	{
		traversal(v, root->left);
	} 

	if (root->right != NULL)
	{
		traversal(v, root->right);
	}
}


int getMinimumDifference(/*TreeNode* root*/) 
{
	TreeNode* root = new TreeNode(1);
 	root->right = new TreeNode(3);
 	root->right->left = new TreeNode(2);

	vector<int> v;
	int d = 0;
	
	traversal(v,root);
	
	int count = v.size();
	for (int index = 0; index < count; index++)
	{
		for (int item = 0; item < count; item++)
		{
			if (item!=index)
			{
				int t = abs(v[index] - v[item]);
				if (t < d || d == 0)
				{
					d = t;
				}
			}
		}
	}
	
	return d;
}