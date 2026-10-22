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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "N";
        }

        string solution = "";
        queue<TreeNode*> q;
        
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front) {
                solution += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            } else {        
                solution += "N,";
            }
        }

        return solution;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> queue;
        queue.push(root);

        while (getline(ss, val, ',')) {
            TreeNode* node = queue.front();
            queue.pop();
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                queue.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                queue.push(node->right);
            }
        }
        return root;

        return nullptr;
    }
};
