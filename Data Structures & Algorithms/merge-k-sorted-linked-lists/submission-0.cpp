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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        while (lists.size() > 1) {
            vector<ListNode*> merged;
            int size = lists.size();
            for (int i = 0; i < size; i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < size ? lists[i + 1] : nullptr;
                merged.push_back(merge2Lists(l1, l2));
            }

            lists = merged;
        }


        return lists[0];
    }

    ListNode* merge2Lists (ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *index = &dummy;

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
        
        if (l1) {
            index->next = l1;
        }

        if (l2) {
            index->next = l2;
        }

        return dummy.next;
    }
};
