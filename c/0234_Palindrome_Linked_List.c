/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(!head || !head->next) return true;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* prev = head;
    struct ListNode* last = slow->next;
    struct ListNode* tmp;
    while(last->next!=NULL){
        tmp = last->next;
        last->next = tmp->next;
        tmp->next = slow->next;
        slow->next = tmp;
    }
    while(slow->next!=NULL){
        slow = slow->next;
        if(prev->val != slow->val) return false;
        prev = prev->next;
    }
    return true;
}
