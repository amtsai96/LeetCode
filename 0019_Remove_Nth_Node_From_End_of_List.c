/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* tmpHead = head;
    struct ListNode* resHead = head;
    if(!tmpHead->next) return NULL;
    int i;
    // move n steps and then add the other ptr to move (len-n) steps until end
    for(i=0;i<n;i++){
        tmpHead = tmpHead->next;
    }
    // if len = n: return the List starts from second one
    if(!tmpHead) return head->next;
    while(tmpHead->next!=NULL){
        tmpHead = tmpHead->next;
        resHead = resHead->next;
    }
    resHead->next = resHead->next->next;
    
    return head;
    
}
