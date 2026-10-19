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
        int size = preorder.size();
        if (size == 0) {
            return nullptr;
        }

        TreeNode* self = new TreeNode(preorder[0]);
        int index_of_self = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
        
        vector<int> preorder_left = vector<int> (preorder.begin() + 1, preorder.begin() + index_of_self + 1);
        vector<int> inorder_left = vector<int> (inorder.begin(), inorder.begin() + index_of_self);

        self->left = buildTree(preorder_left, inorder_left);

        vector<int> preorder_right = vector<int> (preorder.begin() + index_of_self + 1, preorder.end());
        vector<int> inorder_right = vector<int> (inorder.begin() + index_of_self + 1, inorder.end());

        self->right = buildTree(preorder_right, inorder_right);

        return self;
    }


    //     preorder
    //     visit self first
    //     then left then right

    //     inorder
    //     visit left first
    //     then self then right
};
