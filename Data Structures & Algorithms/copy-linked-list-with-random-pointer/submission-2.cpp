/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> link;
        
        Node* head_og = head;
        Node* index_og = head_og;

        Node* head_new = new Node(head_og->val);
        Node* index_new = head_new;

        link[head_og] = head_new;

        while (index_og->next) {
            index_new->next = new Node(index_og->next->val);

            link[index_og->next] = index_new->next;

            index_og = index_og->next;
            index_new = index_new->next;
        }

        index_og = head_og;
        index_new = head_new;

         while (index_og) {
            index_new->random = link[index_og->random];

            index_new = index_new->next;
            index_og = index_og->next;
        }

        return head_new;

    }
};
