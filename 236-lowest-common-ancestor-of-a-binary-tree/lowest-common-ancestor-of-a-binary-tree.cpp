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
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        findPath(root,p,p_path);
        findPath(root,q,q_path);

        int k = min(p_path.size(),q_path.size());
        TreeNode* lca = nullptr;
        for (int i = 0; i < k ; i++){
            if (p_path[i]!=q_path[i]) break;
            lca = p_path[i];
        }

        return lca;

        
    }

    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& result){
        if (root==nullptr) return false;
        result.push_back(root);
        if (root->val == p->val) return true;
        if (findPath(root->left,p,result) || findPath(root->right,p,result)) return true;
        result.pop_back();
        return false;
    }

    
};