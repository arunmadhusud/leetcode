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
//     vector<string> binaryTreePaths(TreeNode* root) {
//         std::vector<int> pathVec;
//         vector<string> paths;
//         if (!root) return {};
//         pathUtil(root,pathVec,paths);
//         return paths;
//     }

//     void pathUtil(TreeNode* root,std::vector<int>& pathVec,vector<string>& paths){  
//         if (!root) return;
//         pathVec.push_back(root->val);      
//         if (!(root->left) && !(root->right)){
//             string path = "";
//             for (size_t i = 0; i < pathVec.size(); i++) {
//                 path += std::to_string(pathVec[i]);
//                 if (i != pathVec.size() - 1) path += "->"; 
//             }
//             paths.push_back(path);
//         }
//         if ((root->left))  pathUtil(root->left,pathVec,paths);
//         if ((root->right)) pathUtil(root->right,pathVec,paths);
//         pathVec.pop_back();
//     }
// };


class Solution {
public:
    void dfs(TreeNode* root, vector<string>& result, string temp){
        if(root==nullptr) return;
        temp += std::to_string(root->val);
        if (!(root->left) && !(root->right)) result.push_back(temp);
        else{
            temp +="->";
            dfs(root->left,result,temp);
            dfs(root->right,result,temp);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, result, "");
        return result;
    }
};