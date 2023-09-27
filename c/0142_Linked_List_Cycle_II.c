/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL) return NULL;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    do{
        // if walk to end, return NULL
        if(fast->next != NULL && fast->next->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        else return NULL;
    }while(fast != NULL && slow != NULL && slow != fast);
    if(fast==NULL || fast->next==NULL || fast->next->next==NULL || slow==NULL) return NULL;
    
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}