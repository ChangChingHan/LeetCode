#https://leetcode.com/problems/binary-tree-inorder-traversal
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
    
    bool traversal(TreeNode* root, vector<int>& v) {
        bool putinorder = false;
        
        if(root == NULL) return putinorder;
            
        if(root->left != NULL) {
            if (traversal(root->left, v) == true){
                v.push_back(root->val);
                putinorder = true;
            }
        }
        
        if(putinorder == false) {
            v.push_back(root->val);
            putinorder = true;
        }
        
        if(root->right != NULL) {
            if (traversal(root->right, v) == false){
                v.push_back(root->val);
            }
        } 
        
        return putinorder;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(root,v);
        return v;
    }
};
