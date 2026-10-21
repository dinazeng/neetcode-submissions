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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* group_prev = dummy;

        while (true) {
            ListNode* kth_node = getKth(group_prev, k);
            if (!kth_node) {
                break;
            }
            ListNode* group_next = kth_node->next;

            ListNode* prev = kth_node->next;
            ListNode* curr = group_prev->next;

            while (curr != group_next) {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode *temp = group_prev->next;
            group_prev->next = kth_node;
            group_prev = temp;
        }

        return dummy->next;
    }

    ListNode* getKth (ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }

        return curr;
    }
};
