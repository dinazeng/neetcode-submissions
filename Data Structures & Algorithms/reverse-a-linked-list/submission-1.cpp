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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* index = head;

        ListNode* prev = nullptr;
        ListNode* next = index->next;
        
        while (index) {
            ListNode* temp = index->next;
            index->next = prev;
            prev = index;
            index = temp;
        }

        return prev;
    }
};
