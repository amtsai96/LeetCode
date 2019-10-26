/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isMirrored(root, root);
    }
    bool isMirrored(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL and t2 == NULL)
            return true;
        else if (t1 == NULL or t2 == NULL)
            return false;
        return (t1->val == t2->val) and isMirrored(t1->right, t2->left) and isMirrored(t2->right, t1->left);
    }
};