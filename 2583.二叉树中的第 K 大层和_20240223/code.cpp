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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        queue<TreeNode *> nodes;
        nodes.push(root);
        vector<long long int> ans;
        ans.push_back(root->val);
        // BFS
        while (!nodes.empty())
        {
            long long sum = 0;
            int sizes = nodes.size();
            for (int i = 0; i < sizes; i++)
            {
                TreeNode *tmp = nodes.front();
                nodes.pop();
                if (tmp->left)
                {
                    nodes.push(tmp->left);
                    sum += tmp->left->val;
                }
                if (tmp->right)
                {
                    nodes.push(tmp->right);
                    sum += tmp->right->val;
                }
            }
            if (sum)
                ans.push_back(sum);
        }
        sort(ans.begin(), ans.end());
        // cout<<ans.size()<<endl;
        if (k > ans.size())
            return -1;
        return ans[ans.size() - k];
    }
};