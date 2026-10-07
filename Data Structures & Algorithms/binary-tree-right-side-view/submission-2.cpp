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

        queue<TreeNode*> q;
        vector<int> solution;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            TreeNode* rightMost = nullptr;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    rightMost = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if (rightMost) {
                solution.push_back(rightMost->val);
            }
        }

        return solution;
    }
};
