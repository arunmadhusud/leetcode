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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = -1;
        findDiameter(root,dia);
        return dia;        
    }

    void findDiameter(TreeNode* root,int& dia){
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        dia = max(dia,lh+rh);
        if(root->left!=nullptr) findDiameter(root->left,dia);
        if(root->right!=nullptr)findDiameter(root->right,dia);
    }
    int findHeight(TreeNode* root){
        if (root==nullptr) return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return max(lh,rh) +1;
    }
};