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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> result;
        if(root==nullptr) return {};
        q.push(root);
        result.push_back({root->val});
        while(!q.empty()){
            vector<int> level_val;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left != nullptr){
                    level_val.push_back(currNode->left->val);
                    q.push(currNode->left);
                } 
                if(currNode->right != nullptr){
                    level_val.push_back(currNode->right->val);
                    q.push(currNode->right);
                }
            }
            if(level_val.size()>0) result.push_back(level_val);
        }
        return result;        
    }
};