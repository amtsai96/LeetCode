// time:O(n), space: O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool flipEquiv_Sub(struct TreeNode* root1, struct TreeNode* root2) {
    if(!root1 && !root2)
    {
        return true;
    }
    if(!(root1 && root2) || root1->val != root2->val)
    {
        return false;
    }

    return ((flipEquiv_Sub(root1->left, root2->left) && flipEquiv_Sub(root1->right, root2->right)) || (flipEquiv_Sub(root1->left, root2->right) && flipEquiv_Sub(root1->right, root2->left)));
}

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    return flipEquiv_Sub(root1, root2);
}