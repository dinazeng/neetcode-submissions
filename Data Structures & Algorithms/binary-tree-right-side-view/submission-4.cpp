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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        queue<pair<TreeNode*, int>> q;
        vector<int> solution;

        q.push({root, 1});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int level = front.second;

            if (node->left) {
                q.push({node->left, level + 1});
            }

            if (node->right) {
                q.push({node->right, level + 1});
            }

            if (q.empty() || q.front().second != level) {
                solution.push_back(node->val);
            }
        }

        return solution;
    }
};
