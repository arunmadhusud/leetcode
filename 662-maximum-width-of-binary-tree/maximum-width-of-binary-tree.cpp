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
        int max_width = 0;
        std::queue<std::pair<TreeNode*,long>> q;
        q.push({root,0});        
        while(!q.empty()){
            int k =  q.size();
            long min_idx = q.front().second;
            long first = q.front().second;
            long last = q.back().second;
            int width = static_cast<int>(last-first) + 1;
            max_width = max(width,max_width);
            for (int i=0; i< k; i++){
                auto curr = q.front();
                TreeNode* currNode = curr.first;
                long idx = curr.second;
                idx -=min_idx;    
                q.pop();
                if(currNode->left != nullptr) q.push({currNode->left, 2*idx+1});
                if(currNode->right != nullptr) q.push({currNode->right, 2*idx+2});
            }
        }
        return max_width;
        
    }
};