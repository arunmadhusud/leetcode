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
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max_elem = INT_MIN;
        dfs(root, max_elem, count );
        return count;        
    }    

    void dfs(TreeNode* root, int max_elem, int& count ){
        if(!root) return;
        if (root->val >= max_elem) count++;
        max_elem = max(root->val,max_elem);
        dfs(root->left,max_elem ,count);
        dfs(root->right,max_elem ,count);
    }
};