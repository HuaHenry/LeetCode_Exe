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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        // 递归做法：
        vector<int> ans_left = inorderTraversal(root->left);
        for (int i = 0; i < ans_left.size(); i++)
        {
            ans.push_back(ans_left[i]);
        }
        ans.push_back(root->val);
        vector<int> ans_right = inorderTraversal(root->right);
        for (int i = 0; i < ans_right.size(); i++)
        {
            ans.push_back(ans_right[i]);
        }
        return ans;
    }
};