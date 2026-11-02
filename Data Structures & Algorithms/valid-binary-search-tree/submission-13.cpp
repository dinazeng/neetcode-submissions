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

        vector<int> inorder;
        buildInOrderTraversal(root, inorder);

        int size = inorder.size();
        for (int i = 1; i < size; i++) {
            if (inorder[i - 1] >= inorder[i]) {
                return false;
            }
        }

        return true;
    }

    void buildInOrderTraversal(TreeNode* root, vector<int> &inorder) {
        if (!root) {
            return;
        }

        buildInOrderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        buildInOrderTraversal(root->right, inorder);
    }
};
