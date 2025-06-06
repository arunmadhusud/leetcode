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
        int bottomval;       
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            bottomval = q.front()->val;
            for (int i = 0; i < k; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left !=nullptr) q.push(curr->left);
                if(curr->right !=nullptr) q.push(curr->right);
            }
        }
        return bottomval;
        
    }
};