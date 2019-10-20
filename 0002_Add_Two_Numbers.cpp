// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        int sum = 0;
        ListNode *result = NULL;
        ListNode **tmp = &result;
        while (l1 != NULL || l2 != NULL || sum > 0)
        {
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*tmp) = new ListNode(sum % 10);
            sum /= 10;
            tmp = &((*tmp)->next);
        }

        return result;
    }
};