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
    bool containsNode(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return false;
        }

        if (root == p) {
            return true;
        }

        return containsNode(root->right, p) || containsNode(root->left, p);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (containsNode(root->right, p) && containsNode(root->right, q)) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (containsNode(root->left, p) && containsNode(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};
