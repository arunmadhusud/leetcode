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
        int max_dia = INT_MIN;
        int md = maxDepth(root,max_dia);  
        return max_dia;      
    }
    int maxDepth(TreeNode* root, int& max_dia) {
        int dia = 0;
        if (root==nullptr) return  -1;
        int leftHeight =  maxDepth(root->left,max_dia);
        if (leftHeight >= 0) dia = dia + leftHeight + 1;
        int rightHeight = maxDepth(root->right,max_dia);
        if (rightHeight >= 0) dia = dia + rightHeight + 1;
        max_dia = max(max_dia,dia);
        return max(leftHeight,rightHeight) + 1;        
    }

};