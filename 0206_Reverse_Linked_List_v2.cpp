/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nextPtr;
        while (cur != NULL)
        {
            nextPtr = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextPtr;
        }
        return prev;
    }
};