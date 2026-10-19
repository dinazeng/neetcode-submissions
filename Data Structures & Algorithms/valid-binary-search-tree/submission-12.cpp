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
        buildInOrder(inorder, root);

        int size = inorder.size();
        for (int i = 1; i < size; i++) {
            if (inorder[i] <= inorder[i - 1]) {
                return false;
            }
        }

        return true;
    }

    void buildInOrder(vector<int> &inorder, TreeNode* root) {
        if (!root) {
            return;
        }

        buildInOrder(inorder, root->left);
        inorder.push_back(root->val);
        buildInOrder(inorder, root->right);
    }

   
};
