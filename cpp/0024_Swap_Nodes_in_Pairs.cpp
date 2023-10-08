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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !(head->next))
            return head;

        ListNode empty = ListNode();
        ListNode *h = head->next, *prev = &empty, *next = NULL;
        ListNode *p = head, *q;

        prev->next = h;

        while (p)
        {
            q = p->next;
            if (!q)
                break;

            next = q->next;
            q->next = p;
            p->next = next;
            prev->next = q;

            prev = p;
            p = p->next;
        }

        return h;
    }
};

// solution 2
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !(head->next))
            return head;

        ListNode *prev = head, *next, *cur = prev->next->next;

        head = head->next;
        head->next = prev;

        while (cur && cur->next)
        {
            next = cur->next->next;
            prev->next = cur->next;
            prev = cur;
            cur->next->next = cur;
            cur = next;
        }

        prev->next = cur;

        return head;
    }
};