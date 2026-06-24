/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head) {
            return nullptr;
        }

        int size = 0;
        ListNode* index = head;

        while (index) {
            index = index->next;
            size++;
        }

        int remove = size - n;
        if (remove == 0) {
            return head->next;
        } 

        index = head;
        for (int i = 0; i < remove - 1; i++) {
            index = index->next;
        }

        index->next = index->next->next;

        return head;
    }
};
