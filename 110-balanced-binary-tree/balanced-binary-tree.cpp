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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // int lh = findHeight(root->left);
        // int rh = findHeight(root->right);
        // if(abs(lh-rh)>1) return false;
        // return (isBalanced(root->left) && isBalanced(root->right));
        int height = findHeight(root);
        if (height==-1) return false;
        else return true;

    }
    int findHeight(TreeNode* root) {
        if (root==nullptr) return  0;
        int lh =  findHeight(root->left);
        if (lh==-1) return -1;
        int rh =  findHeight(root->right);
        if (rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh) + 1;        
    }
};