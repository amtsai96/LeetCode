/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* prv = NULL;
    struct ListNode* cur = head;
    struct ListNode* nxt;
    while(cur != NULL){
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
    return prv;
    
}

