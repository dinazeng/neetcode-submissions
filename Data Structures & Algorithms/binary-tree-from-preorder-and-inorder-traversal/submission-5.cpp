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
    int pre_index = 0;
    int in_index = 0;
    
    TreeNode* traverseTree(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (pre_index >= preorder.size()) {
            return nullptr;
        }

        if (inorder[in_index] == limit) {
            in_index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_index++]);

        root->left = traverseTree(preorder, inorder, root->val);
        root->right = traverseTree(preorder, inorder, limit);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traverseTree(preorder, inorder, INT_MAX);
    }
};
