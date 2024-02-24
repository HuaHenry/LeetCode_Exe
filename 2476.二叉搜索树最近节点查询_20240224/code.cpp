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
    vector<int> tree;

    vector<vector<int> > closestNodes(TreeNode *root, vector<int> &queries)
    {
        // 中序遍历存储结果
        dfs(root);
        sort(tree.begin(), tree.end());
        // 二分查找
        vector<vector<int> > ans;
        for (auto it : queries)
        {
            int pos = lower_bound(tree.begin(), tree.end(), it) - tree.begin();
            int max_number = pos >= tree.size() ? -1 : tree[pos];
            int min_number = pos >= tree.size() ? tree[tree.size() - 1] : (tree[pos] == it ? tree[pos] : (pos == 0 ? -1 : tree[pos - 1]));
            vector<int> tmp;
            tmp.push_back(min_number);
            tmp.push_back(max_number);
            ans.push_back(tmp);
        }
        return ans;
    }

    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        tree.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};