/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int length(struct ListNode* head)
 {
    if (head == NULL) return 0;
    return 1 + length(head->next); 
 }

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    int list_len = length(head);
    struct ListNode** ans = (struct ListNode**)malloc(k * sizeof(struct ListNode**));
    struct ListNode* tmp = head;
    struct ListNode* p;
    int reminder = list_len % k;
    int node_n = list_len / k;
    int n;

    *returnSize = k;

    for (int i = 0; i < k; i++)
    {
        n = (reminder > 0) ? node_n + 1 : node_n;

        ans[i] = (struct ListNode*)calloc(1, sizeof(struct ListNode));

        if (n == 0)
            ans[i] = NULL;
        else
        {
            p = ans[i];

            for (int j=0; j<n; j++)
            {
                p->val = tmp->val;
                tmp = tmp->next;

                if (j < n-1)
                {
                    p = p->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
                }
            }
        }

        reminder--;
    }

    return ans;
}