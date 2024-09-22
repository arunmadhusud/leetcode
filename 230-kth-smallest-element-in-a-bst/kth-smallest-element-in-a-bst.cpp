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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inOrder(root, result);  // Perform in-order traversal to fill the result vector
        return result[k - 1];   // Return the k-th smallest element
    }
    
    void inOrder(TreeNode* current, vector<int>& result) {
        if (current == nullptr) return;
        
        inOrder(current->left, result);   // Traverse left subtree
        result.push_back(current->val);   // Visit current node
        inOrder(current->right, result);  // Traverse right subtree
    }
};