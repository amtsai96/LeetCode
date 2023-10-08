// time: O(n), space: O(1)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) return head;

        ListNode *dummy = new ListNode(0, head);
        ListNode *p = head, *prev = dummy;

        while(p && p->next)
        {
            if (p->val == p->next->val)
            {
                while(p->next && p->val == p->next->val) p = p->next;
                prev->next = p->next;
            }
            else prev = prev->next;
            p = p->next;
        }

        return dummy->next;
    }
};