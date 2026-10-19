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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !q || !p) {
            return nullptr;
        }

        if (contains(p, root->left) && contains(q, root->left)) {
            return lowestCommonAncestor(root->left, p, q);
        } 

        if (contains(p, root->right) && contains(q, root->right)) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }

    bool contains(TreeNode* node, TreeNode* root) {
        if (!root) {
            return false;
        }

        if (root->val == node->val) {
            return true;
        }

        return contains(node, root->left) || contains(node, root->right);
    }
};
