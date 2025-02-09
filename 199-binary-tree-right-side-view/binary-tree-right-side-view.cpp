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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root==nullptr) return result;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int level = curr.second;
            mp[level] = node->val;
            if(node->left !=nullptr) q.push({node->left,level+1});
            if(node->right !=nullptr) q.push({node->right,level+1});
        }

        for (const auto& elem : mp){
            result.push_back(elem.second);
        }

        return result;
        
    }
};