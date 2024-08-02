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
    // 重点：子树所有元素对于root的判断
    bool checkTree(TreeNode *root, long long int l, long long int r)
    {
        // 递归解决问题
        if (!root)
            return true;
        if (root->left && (root->val <= root->left->val || !(root->left->val > l && root->left->val < r)))
            return false;
        if (root->right && (root->val >= root->right->val || !(root->right->val > l && root->right->val < r)))
            return false;
        if (checkTree(root->left, l, root->val) && checkTree(root->right, root->val, r) && root->val < r && root->val > l)
            return true;
        return false;
    }

    bool isValidBST(TreeNode *root)
    {
        return checkTree(root, -21474836480, 21474836470);
    }
};