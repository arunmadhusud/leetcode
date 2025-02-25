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
        if (root==nullptr) return {};
        vector<vector<int>> result;
        std::queue<TreeNode*> q;
        q.push(root);
        int level;        
        while(!q.empty()){
            level +=1;
            std::vector<int> tmp;
            int k =  q.size();
            for (int i=0; i< k; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
                tmp.push_back(curr->val);
            }
            if (level % 2 == 0) std::reverse(tmp.begin(),tmp.end());
            result.push_back(tmp);
        }
        return result;
    }
};