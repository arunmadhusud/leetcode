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
        if (root==nullptr) return {};
        vector<int> result;
        DFS(root,result);
        return result;        
    }

    void DFS(TreeNode* root,vector<int>& result ){
        if(root->left !=nullptr) DFS(root->left,result);
        result.push_back(root->val);
        if(root->right !=nullptr) DFS(root->right,result);
    }

};