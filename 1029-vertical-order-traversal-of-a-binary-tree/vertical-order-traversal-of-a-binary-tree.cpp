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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int x_axis = curr.second.first;
            int level = curr.second.second;
            mp[x_axis][level].insert(node->val);
            if(node->left !=nullptr){
                q.push({node->left,{x_axis-1,level+1}});
            }
            if(node->right !=nullptr){
                q.push({node->right,{x_axis+1,level+1}});
            }
        }

        for (const auto& x_axis : mp){
            vector<int> tmp;
            for (const auto& level : x_axis.second){
                for (const auto& e : level.second) tmp.push_back(e);
            }
            
            result.push_back(tmp);
        }

        return result;
        
    }
};