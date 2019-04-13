#include "stdafx.h"

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal_tree(vector<vector<int>> &v, int level, TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	if (v.size() <= level)
	{
		vector<int> temp;
		v.push_back(temp);
	}

	v[level].push_back(root->val);

	TreeNode* roottemp = NULL;
	if (root != NULL && root->left != NULL)
	{
		roottemp = root->left;
		traversal_tree(v, level+1, roottemp);
	}
	roottemp = NULL;
	if (root != NULL && root->right != NULL)
	{
		roottemp = root->right;
		traversal_tree(v, level+1, roottemp);
	}
}

vector<double> averageOfLevels(TreeNode* root) 
{
// 	TreeNode* root = new TreeNode(3);
// 	root->left = new TreeNode(9);
// 	root->right = new TreeNode(20);
// 	root->right->right = new TreeNode(7);
// 	root->right->left = new TreeNode(15);


	vector<vector<int>> v;
	vector<double> result;

	traversal_tree(v,0,root);
	
	int count = v.size();
	for (int level = 0; level < count; level++)
	{
		int levelcount = v[level].size();
		double d = 0;

		for (int index = 0; index < levelcount; index++)
		{
			d += v[level][index];
		}
		
		result.push_back((double)d / levelcount);

	}

	return result;
}
