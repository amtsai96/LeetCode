/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int* nums, int left, int right){
    if(left > right) return NULL;
    int x = (left+right)/2;
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = nums[x];
    node->left = createNode(nums, left, x-1);
    node->right = createNode(nums, x+1, right);
    
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return createNode(nums, 0, numsSize-1);
}


