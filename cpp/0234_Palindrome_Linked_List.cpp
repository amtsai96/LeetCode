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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if (head == NULL || head->next == NULL) return true;

        // check the middle node
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // odd nodes num
        if (fast != NULL && fast->next == NULL)
        {
            slow = slow->next;
        }

        // reverse last half list
        ListNode* prev = NULL;
        ListNode* tmp = NULL;

        while (slow != NULL && slow->next != NULL)
        {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        if (slow != NULL) slow->next = prev;

        // compare two halves
        fast = head;
        while (slow != NULL && fast != NULL)
        {
            if (slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};