/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        Node* root = new Node (node->val);
        Node* index = root;

        queue<Node*> q;
        unordered_map<Node*, Node*> seen;
        
        q.push(node);
        seen[node] = root;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            vector<Node*> neighbors;
            for (Node* n : front->neighbors) {
                if (!seen.contains(n)) {
                    Node* newNode = new Node(n->val);
                    neighbors.push_back(newNode);
                    seen[n] = newNode;
                    q.push(n);
                } else {
                    neighbors.push_back(seen[n]);
                }
            }

            index->neighbors = neighbors;

            if (!q.empty()) {
                index = seen[q.front()];
            }
        }


        return root;
    }
};
