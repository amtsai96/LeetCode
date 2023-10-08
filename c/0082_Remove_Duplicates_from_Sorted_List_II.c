// time: O(n), space: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head || !(head->next)) return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *p = head, *prev = dummy;

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