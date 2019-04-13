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
	if(root == NULL)
		return;

	v.push_back(root->val);

	if (root->left != NULL)
	{
		traversal(v,root->left);
	}

	if (root->right != NULL)
	{
		traversal(v,root->right);
	}
}

bool findTarget(TreeNode* root, int k) 
{
	vector<int> v;
	traversal(v, root);

	int count = v.size();
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (i != j)
			{
				if (v[i]+v[j] == k)
				{
					return true;
				}
			}
		}
	}

	return false;
}