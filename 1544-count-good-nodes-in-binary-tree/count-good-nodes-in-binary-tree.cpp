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
    int goodNodes(TreeNode* root) {
        // std::vector<int> pathVec;
        int count = 0;
        int max_elem = INT_MIN;
        dfs(root, max_elem, count );
        return count;        
    }    
    // int findMax(std::vector<int>& pathVec){
    //     int max_elem = INT_MIN;
    //     for (auto elem : pathVec) max_elem = max(max_elem,elem);
    //     return max_elem;
    // }
    // void dfs(TreeNode* root, std::vector<int>& pathVec, int& count ){
    //     if(!root) return;
    //     pathVec.push_back(root->val);
    //     if (root->val >= findMax(pathVec)) count++;
    //     dfs(root->left,pathVec,count);
    //     dfs(root->right,pathVec,count);
    //     pathVec.pop_back();
    // }

    void dfs(TreeNode* root, int max_elem, int& count ){
        if(!root) return;
        if (root->val >= max_elem) count++;
        max_elem = max(root->val,max_elem);
        dfs(root->left,max_elem ,count);
        dfs(root->right,max_elem ,count);
        // pathVec.pop_back();
    }
};