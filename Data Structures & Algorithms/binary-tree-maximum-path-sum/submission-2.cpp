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
        bestPath(root, best);
        return best;
    }

    int bestPath(TreeNode* root, int &best) {
        if (!root) return 0;

        int left = max(0, bestPath(root->left, best));
        int right = max(0, bestPath(root->right, best));

        best = max(best, left + right + root->val);

        return root->val + max(left, right);
    }
};
