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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
        
        vector<int> newPreOrderLeft = vector<int>(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> newInOrderLeft = vector<int> (inorder.begin(), inorder.begin() + mid);

        root->left = buildTree(newPreOrderLeft, newInOrderLeft);

        vector<int> newPreOrderRight = vector<int>(preorder.begin() + mid + 1, preorder.end());
        vector<int> newInOrderRight = vector<int> (inorder.begin() + mid + 1, inorder.end());

        root->right = buildTree(newPreOrderRight, newInOrderRight);

        return root;
    }
};
