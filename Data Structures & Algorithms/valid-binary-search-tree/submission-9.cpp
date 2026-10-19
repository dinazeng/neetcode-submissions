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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        vector<int> in_order_traversal;

        buildInOrderTraversal(in_order_traversal, root);

        int size = in_order_traversal.size();
        for (int i = 1; i < size; i++) {
            if (in_order_traversal[i - 1] >= in_order_traversal[i]) {
                return false;
            }
        }

        return true;
    }

    void buildInOrderTraversal(vector<int> &vec, TreeNode* &root) {
        if (!root) {
            return;
        }

        buildInOrderTraversal(vec, root->left);
        vec.push_back(root->val);
        buildInOrderTraversal(vec, root->right);
    }
};
