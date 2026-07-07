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
    unordered_map<int, vector<int>> result;
    void levelProcessor(TreeNode* root, int level) {
        if (root) {
            result[level].push_back(root->val);
            levelProcessor(root->left, level + 1);
            levelProcessor(root->right, level + 1);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        levelProcessor(root, 0);
        
        vector<vector<int>> levelOrderTraversal(result.size());
        for (auto p : result) {
            levelOrderTraversal[p.first] = p.second;
        }

        return levelOrderTraversal;
    }
};
