/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_result;
        vector<TreeNode*> q_result;
        TreeNode* result = nullptr;
        lca(root,p,p_result);
        lca(root,q,q_result);
        size_t min_size = std::min(p_result.size(),q_result.size());
        for(size_t i = 0 ; i < min_size; i++){
            if (p_result[i]!=q_result[i]) break;
            result = p_result[i];
        }
        return result;        
    }

    bool lca(TreeNode* root,TreeNode* p, std::vector<TreeNode*>& result){
        if (!root) return false;
        result.push_back(root);
        if (root==p) return true;       
        if (lca(root->left,p,result) || lca(root->right,p,result)) return true;
        result.pop_back();
        return false;
    }
};