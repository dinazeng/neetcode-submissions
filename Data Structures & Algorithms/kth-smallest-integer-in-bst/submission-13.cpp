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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        build(inorder, root, k);

        return inorder[k - 1];
    }

    void build (vector<int> &vec, TreeNode* root, int &k) {
        if (!root) {
            return;
        }

        build(vec, root->left, k);
        vec.push_back(root->val);

        if (vec.size() == k) {
            return;
        }

        build(vec, root->right, k);
    }
};
