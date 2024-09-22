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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        return insertBalanced(root,0,nums.size()-1,nums );
        
    }
    TreeNode* insertBalanced(TreeNode* root,int start,int end,vector<int>& nums )
    {   
        if (start > end) return nullptr;
        int mid = start + (end-start) / 2 ;
        if (root==nullptr) root = getNewNode(nums[mid]);
        root->left = insertBalanced(root->left,start,mid-1,nums);
        root->right = insertBalanced(root->right,mid+1,end,nums);
        return root;

    }
    TreeNode* getNewNode(int data){
        return new TreeNode(data);
    }
};