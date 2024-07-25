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
    int ans = 0;

    int checkTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_dis = root->left ? checkTree(root->left) + 1 : 0;
        int right_dis = root->right ? checkTree(root->right) + 1 : 0;
        // cout<<root->val<<' '<<left_dis<<' '<<right_dis<<endl;
        ans = max(ans, left_dis + right_dis);
        return max(left_dis, right_dis);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        checkTree(root);
        return ans;
    }
};