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
        vector<int> v; 
        dfs(v, root, k);
        
        return v[k - 1];
    }

    void dfs (vector<int> &v, TreeNode* root, int k) {
        if (!root || k == v.size()) {
            return;
        }

        dfs(v, root->left, k);

        v.push_back(root->val);

        dfs(v, root->right, k);
    }
};
