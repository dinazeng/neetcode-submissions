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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* index = head;

        int carry = 0;

        while (l1 || l2 || carry) {
            int next = carry;

            if (l1) {
                next += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                next += l2->val;
                l2 = l2->next;
            }

            carry = next / 10;

            index->next = new ListNode(next % 10);
            index = index->next;
        }

        return head->next;
    }
};
