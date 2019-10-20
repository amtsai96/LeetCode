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
    int getSize(ListNode *l)
    {
        ListNode *p = l;
        int count = 0;
        while (p != NULL)
        {
            ++count;
            p = p->next;
        }
        return count;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        vector<int> v1, v2;
        while (l1)
        {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int i1 = v1.size() - 1;
        int i2 = v2.size() - 1;
        int carry = 0;
        ListNode *result = new ListNode(0);
        ListNode *ptr = result;

        while (i1 >= 0 || i2 >= 0 || carry > 0)
        {
            int sum = (i1 >= 0 ? v1[i1] : 0) + (i2 >= 0 ? v2[i2] : 0) + carry;
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            ListNode *cur = new ListNode(sum);
            cur->next = ptr->next;
            ptr->next = cur;

            if (i1 >= 0)
                i1 -= 1;
            if (i2 >= 0)
                i2 -= 1;
        }

        return result->next;
    }
};