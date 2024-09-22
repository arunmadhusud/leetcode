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
        return isBSTcheck(root,LONG_MIN,LONG_MAX);
        
    }
    bool isBSTcheck(TreeNode* root, long MinVal, long MaxVal)
    {
        if(root==nullptr) return true;
        if(root->val > MinVal && root->val < MaxVal && isBSTcheck(root->left,MinVal,root->val) && isBSTcheck(root->right,root->val,MaxVal))return true;
        else return false;
    }
};