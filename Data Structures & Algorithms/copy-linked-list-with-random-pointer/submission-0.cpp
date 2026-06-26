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

        map <Node*, Node*> originalToNew;

        Node* headOriginal = head;
        Node* indexOriginal = headOriginal;

        Node* newHead = new Node(headOriginal->val);
        Node* newIndex = newHead;

        originalToNew[headOriginal] = newHead; 

        while (indexOriginal->next) {
            newIndex->next = new Node (indexOriginal->next->val);

            originalToNew[indexOriginal->next] = newIndex->next;

            newIndex = newIndex->next;
            indexOriginal = indexOriginal->next;
        }


        indexOriginal = headOriginal;
        newIndex = newHead;

        while (indexOriginal) {
            newIndex->random = originalToNew[indexOriginal->random];

            newIndex = newIndex->next;
            indexOriginal = indexOriginal->next;
        }

        return newHead;
    }
};
