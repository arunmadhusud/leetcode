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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        int p = Pathsum(root,max_sum);
        return max_sum;        
    }

    int Pathsum(TreeNode* root, int& max_sum){
        if (root==nullptr) return 0;
        int leftsum = max(0,Pathsum(root->left,max_sum));
        int rightsum = max(0,Pathsum(root->right,max_sum));
        max_sum = max(root->val + leftsum + rightsum, max_sum);
        return (root->val + max(leftsum,rightsum));
    }
};