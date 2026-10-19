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

        vector<int> right_most;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int index = 0;
            while (index < size) {
                TreeNode* node = q.front();

                if (index == size - 1) {
                    right_most.push_back(node->val);
                }

                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

                index++;
            }
        }

        return right_most;
    }
};
