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
        if (root==nullptr) return {};
        std::vector<vector<int>> result;
        std::map<int,std::map<int,vector<int>>> mp;
        std::queue<std::pair<TreeNode*,std::pair<int,int>>> q;        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* currnode = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            mp[x][y].push_back(currnode->val);
            if(currnode ->left != nullptr) q.push({currnode ->left,{x-1,y+1}});
            if(currnode ->right != nullptr) q.push({currnode ->right,{x+1,y+1}});
        }

        for (auto elem1 : mp){
            std::vector<int> tmp;
            for (auto elem2 : elem1.second){
                std::sort(elem2.second.begin(),elem2.second.end());
                tmp.insert(tmp.end(), elem2.second.begin(), elem2.second.end());
            }
            result.push_back(tmp);
        }

        return result;

        
    }
};