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
    int widthOfBinaryTree(TreeNode* root) {
        if (root==nullptr) return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxWidth = 0;
        while(!q.empty()){
            int k = q.size();
            unsigned long long min_idx = q.front().second;
            unsigned long long max_idx = q.back().second;
            maxWidth = max(maxWidth,static_cast<int>(max_idx - min_idx+1));

            for(int i = 0; i < k; i++){
                pair<TreeNode*,unsigned long long> curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                unsigned long long idx = curr.second;
                idx -=min_idx;
                if(node->left !=nullptr) q.push({node->left,2*idx+1});
                if(node->right !=nullptr) q.push({node->right,2*idx+2});

            }
        }

        return maxWidth;        
        
    }
};