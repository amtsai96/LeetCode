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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        unordered_set<ListNode *> seen;
        while (head != NULL)
        {
            unordered_set<ListNode *>::iterator it = seen.find(head);
            if (it != seen.end())
                return true;
            else
                seen.insert(head);
            head = head->next;
        }
        return false;
    }
};