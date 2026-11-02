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
        int max_el = INT_MIN;
        getPath(root, max_el);

        return max_el;
    }

    int getPath(TreeNode* root, int &max_el) {
        if (!root) return 0;

        int right = max(getPath(root->right, max_el), 0);
        int left = max(getPath(root->left, max_el), 0);

        max_el = max(max_el, right + left + root->val);


        return max(right, left) + root->val;
    }
};
