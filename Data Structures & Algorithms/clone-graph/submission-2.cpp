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

        queue<Node*> q;
        unordered_map<Node*, Node*> seen;

        Node* head = new Node(node->val);
        q.push(node);
        seen[node] = head;

        Node* index = head;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            vector<Node*> neighbours;
            for (Node* neighbour : front->neighbors) {
                if (!seen.contains(neighbour)) {
                    Node* neighbour_copy = new Node(neighbour->val);
                    neighbours.push_back(neighbour_copy);
                    seen[neighbour] = neighbour_copy;
                    
                    q.push(neighbour);
                } else {
                    neighbours.push_back(seen[neighbour]);
                }
            }

            index->neighbors = neighbours;

            if (!q.empty()) {
                index = seen[q.front()];
            }
        }

        return head;
    }
};
