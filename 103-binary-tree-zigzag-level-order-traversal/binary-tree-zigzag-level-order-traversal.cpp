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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
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
            if (flag==0){
                result.push_back(currLevel);
                flag = 1;
            }
            else{
                reverse(currLevel.begin(),currLevel.end());
                result.push_back(currLevel);
                flag = 0;
            }
        }
        return result;
        
    }
};