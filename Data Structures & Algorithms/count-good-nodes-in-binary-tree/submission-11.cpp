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
        int best = INT_MIN;
        return countNodes(root, best);
    }

    int countNodes(TreeNode* root, int best) {
        if (!root) {
            return 0;
        }

        int result = (root->val >= best) ? 1 : 0;
        best = max(root->val, best);

        result += countNodes(root->left, best);
        result += countNodes(root->right, best);

        return result;
    }
};
