/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversal2(root,result);
        return result;       
        
    }
    void inorderTraversal2(TreeNode* root,vector<int>& result) {
        if (root!=nullptr){
            if(root->left != nullptr) inorderTraversal2(root->left,result);
            result.push_back(root->val);
            if(root->right != nullptr) inorderTraversal2(root->right, result);
        }
       
    }
};