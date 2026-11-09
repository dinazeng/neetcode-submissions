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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        ListNode* index = head;
        vector<ListNode*> real_list;

        while (index) {
            real_list.push_back(index);
            index = index->next;
        }

        int l = 0;
        int r = real_list.size() - 1;

        while (l < r) {
            real_list[l]->next = real_list[r];
            l++;

            if (l >= r) break;

            real_list[r]->next = real_list[l];
            r--;
        }

        real_list[l]->next = nullptr;
    }
};
