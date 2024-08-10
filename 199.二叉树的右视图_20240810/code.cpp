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
    int ans[105];      // 存储实时替换的最右节点
    int max_depth = 0; // 存储最大深度

    void search(int depth, TreeNode *root)
    {
        // 中序遍历
        if (!root)
            return;
        max_depth = max(max_depth, depth);
        search(depth + 1, root->left);
        ans[depth] = root->val;
        search(depth + 1, root->right);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return vector<int>{};
        search(0, root);
        vector<int> res;
        for (int i = 0; i <= max_depth; i++)
        {
            res.push_back(ans[i]);
        }
        return res;
    }
};