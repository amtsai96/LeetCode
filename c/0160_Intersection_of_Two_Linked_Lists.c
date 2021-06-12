/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL || headB==NULL) return NULL;
    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;
    while(p1!=NULL && p2!=NULL && p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
        if(p1 == p2) return p1;
        if(p1 == NULL) p1 = headB;
        if(p2 == NULL) p2 = headA;
    }
    return p1;
    
}