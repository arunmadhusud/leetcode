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
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         std::priority_queue<int> pq;
//         for ( int i = 0; i<k; i++) pq.push(INT_MAX);
//         dfs(root,pq,k);
//         return pq.top();
        
//     }
//     void dfs(TreeNode* root,std::priority_queue<int>& pq,int& k ){
//         if (!root) return;
//         if (k < pq.size()) pq.push(root->val);
//         else if (root->val < pq.top()) {
//             pq.pop();
//             pq.push(root->val);
//         }
//         dfs(root->left,pq,k);
//         dfs(root->right,pq,k);
//     }
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int elem = -1;  
        dfs(root, elem, k);
        return elem;      
    }

    bool dfs(TreeNode* root, int& elem, int& k) {
        if (!root) return false;   
        if (dfs(root->left, elem, k)) return true;
        k--;
        if (k == 0) {
            elem = root->val;
            return true;
        }
        if(dfs(root->right, elem, k)) return true;
        return false;
    }
};
