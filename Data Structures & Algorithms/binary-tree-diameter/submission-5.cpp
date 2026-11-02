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
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;

        bestPath(root, best);

        return best;
    }

    int bestPath (TreeNode* root, int &best) {
        if (!root) {
            return 0;
        }

        int left = bestPath(root->left, best);
        int right = bestPath(root->right, best);

        best = max (left + right, best);

        return max (left, right) + 1;
    }
};
