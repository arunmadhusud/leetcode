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
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        return isBST(root,LONG_MIN,LONG_MAX);
        
    }
    bool isBST(TreeNode* root, long min, long max){
        if(root ==nullptr) return true;
        if(root->val < max && root->val > min && isBST(root->left,min,root->val) && isBST(root->right,root->val,max)) return true;
        else return false;
    }
};