/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool checkTree(TreeNode *l, TreeNode *r)
    {
        if (l && !r || !l && r)
            return false;
        if (!l && !r)
            return true;
        if (checkTree(l->left, r->right) && checkTree(l->right, r->left) && (l->val == r->val))
            return true;
        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        TreeNode *l_root = root->left;
        TreeNode *r_root = root->right;
        return checkTree(l_root, r_root);
    }
};