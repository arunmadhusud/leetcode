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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> result;
        // if (root==nullptr) return result[-1][0];
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int> currLevel;
            for (int i = 0; i < k; i++){
                TreeNode* curr = q.front();
                currLevel.push_back(curr->val);
                q.pop();
                if(curr->left !=nullptr) q.push(curr->left);
                if(curr->right !=nullptr) q.push(curr->right);
            }
            result.push_back(currLevel);
        }
        return result[result.size() - 1][0];
        
    }
};