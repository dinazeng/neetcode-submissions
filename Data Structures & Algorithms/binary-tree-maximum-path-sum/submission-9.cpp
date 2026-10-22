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
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        dfs(root, best);
        return best;
    }

    int dfs (TreeNode* root, int &best) {
        if (!root) {
            return 0;
        }

        int left = max(0, dfs(root->left, best));
        int right = max(0, dfs(root->right, best));

        best = max(best, left + right + root->val);

        return max(left, right) + root->val;
    }
};
