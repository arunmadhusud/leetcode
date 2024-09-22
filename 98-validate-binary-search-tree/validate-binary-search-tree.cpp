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
        return isBST(root, LONG_MIN, LONG_MAX);
    }
    bool isBST(TreeNode* root, long minVal, long maxVal){
        if(root == nullptr) return true;
        return (root->val > minVal && root->val < maxVal && isBST(root->left,minVal,root->val) && isBST(root->right,root->val,maxVal));
    }
};