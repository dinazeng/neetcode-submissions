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

        unordered_map<Node*, Node*> copy;
        Node* head = node;
        Node* new_head = new Node(head->val);

        copy[head] = new_head;

        queue<pair<Node*, Node*>> q;
        q.push({head, nullptr});

        while (!q.empty()) {
            Node* parent = q.front().second;
            Node* og = q.front().first;
            q.pop();

            Node* cpy = copy[og];

            for (Node* nei : og->neighbors) {
                if (!copy.contains(nei)) {
                    Node* new_nei = new Node(nei->val);
                    copy[nei] = new_nei;
                    q.push({nei, og});
                } 

                cpy->neighbors.push_back(copy[nei]);
            }
        }

        return new_head;
    }
};
