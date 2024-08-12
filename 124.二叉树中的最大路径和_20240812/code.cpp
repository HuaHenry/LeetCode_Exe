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
    // 维护记录最大路径和
    int res = INT_MIN;

    int maxSum(TreeNode *root)
    {
        if (!root)
            return 0;
        // 递归计算左右节点
        int left = max(maxSum(root->left), 0);
        int right = max(maxSum(root->right), 0);
        res = max(res, left + right + root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        maxSum(root);
        return res;
    }
};