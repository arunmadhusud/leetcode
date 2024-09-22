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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;  // Corrected the type of result

        if (root == nullptr) {
            return result;  // Return empty result if root is null
        }

        queue<TreeNode*> Queue;
        Queue.push(root);

        while (!Queue.empty()) {
            int currLevel = Queue.size();
            vector<int> currResult;  // This holds the nodes at the current level

            for (int i = 0; i < currLevel; i++) {
                TreeNode* current = Queue.front();
                Queue.pop();

                // Push the current node's value into the current level result
                currResult.push_back(current->val);

                // Push left and right children into the queue if they exist
                if (current->left != nullptr) {
                    Queue.push(current->left);
                }
                if (current->right != nullptr) {
                    Queue.push(current->right);
                }
            }
            // Add the current level's result to the final result
            result.push_back(currResult);
        }

        return result;
    }
};