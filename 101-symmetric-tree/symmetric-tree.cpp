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
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        return isSym(root->left,root->right);
        
    }

    bool isSym(TreeNode* p,TreeNode* q ){
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        if(p->val!=q->val) return false;
        // if ((p->left->val != q->right->val) || (p->right->val != q->left->val)) return false;
        return isSym(p->left,q->right) && isSym(p->right,q->left);
        
    }
};