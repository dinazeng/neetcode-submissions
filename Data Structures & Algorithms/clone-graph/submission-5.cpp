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

        unordered_map<Node*, Node*> link;

        Node* head = new Node(node->val);
        link[node] = head;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* front = q.front();
            Node* copy = link[front];
            q.pop();

            for (Node* nei : front->neighbors) {
                if (!link.contains(nei)) {
                    Node* new_nei = new Node(nei->val);
                    link[nei] = new_nei;

                    q.push(nei);
                }

                Node* next = link[nei];
                copy->neighbors.push_back(next);
            }
        }
        
        return head;
    }
};
