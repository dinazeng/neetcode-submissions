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
        if (!root) {
            return 0;
        }

        vector<int> v; 
        helper(v, root);
        
        return v[k - 1];
    }

    void helper (vector<int> &v, TreeNode* &root) {
        if (!root) {
            return;
        }

        helper(v, root->left);

        cout << root->val << endl;
        v.push_back(root->val);

        helper(v, root->right);
    }
};
