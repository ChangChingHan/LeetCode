# https://leetcode.com/problems/validate-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, int* lower, int* upper) {
        if (root == NULL) {
            return true;
        }
        
        if (lower != NULL && root->val <= *lower) return false;
        if (upper != NULL && root->val >= *upper) return false;
        
        return isValidBST(root->left,lower,&root->val) && isValidBST(root->right,&root->val,upper);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        
        return isValidBST(root, NULL, NULL);   
        
    }
};
