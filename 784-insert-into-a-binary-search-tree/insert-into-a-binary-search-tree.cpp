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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            root = getNewnode(val);
            return root;
        }
        else if (root->val >= val){
            root->left = insertIntoBST(root->left,val);            
        }
        else root->right = insertIntoBST(root->right,val);
        return root;
        
    }
    TreeNode* getNewnode(int data){
        return new TreeNode(data);
    }
};