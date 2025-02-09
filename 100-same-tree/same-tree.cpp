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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* p_curr = q1.front();
            q1.pop();
            TreeNode* q_curr = q2.front();
            q2.pop();
            if (p_curr==nullptr && q_curr==nullptr) continue;            
            if (p_curr==nullptr || q_curr==nullptr || p_curr->val != q_curr->val) return false;
            q1.push(p_curr->left);
            q2.push(q_curr->left);
            q1.push(p_curr->right);
            q2.push(q_curr->right);      

        }
        return true;
    }
};