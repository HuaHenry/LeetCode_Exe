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
    int findNum(TreeNode *root, long long int targetSum)
    {
        if (!root)
            return 0;
        // cout<<root->val<<' '<<targetSum<<endl;
        return (root->val == targetSum ? 1 : 0) + findNum(root->left, targetSum - root->val) + findNum(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        // 思路：dfs爆搜，注意不要剪枝
        if (!root)
            return 0;
        return findNum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};