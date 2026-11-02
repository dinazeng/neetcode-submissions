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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        ListNode head(0);
        ListNode *index = &head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                index->next = l1;

                l1 = l1->next;
            } else {
                index->next = l2;

                l2 = l2->next;
            }

            index = index->next;
        }

        while (l1) {
            index->next = l1;
            l1 = l1->next;

            index = index->next;
        }

        while (l2) {
            index->next = l2;
            l2 = l2->next;

            index = index->next;
        }


        return head.next;
    }
};
