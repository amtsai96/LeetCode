/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct ListNode* list;
    if(l1->val < l2->val){
        list = l1;
        l1 = l1->next;
    }
    else{
        list = l2;
        l2 = l2->next;
    }
    struct ListNode* l = list;
    while(l1!=NULL || l2!=NULL){
        if(!l1){
            l->next = l2;
            l2 = l2->next;
        }
        else if(!l2){
            l->next = l1;
            l1 = l1->next;
        }
        else{
            if(l1->val < l2->val){
                l->next = l1;
                l1 = l1->next;
            }
            else{
                l->next = l2;
                l2 = l2->next;
            }
        }
        l = l->next;
    }
    return list;

}

