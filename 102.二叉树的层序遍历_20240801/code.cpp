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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;
        queue<TreeNode *> qNode;
        qNode.push(root);
        while (!(qNode.empty()))
        {
            vector<int> tmp;
            queue<TreeNode *> nodetmp;
            while (!(qNode.empty()))
            {
                TreeNode *now = qNode.front();
                qNode.pop();
                if (now)
                {
                    tmp.push_back(now->val);
                    if (now->left)
                        nodetmp.push(now->left);
                    if (now->right)
                        nodetmp.push(now->right);
                }
            }
            if (tmp.size() != 0)
                ans.push_back(tmp);
            qNode = nodetmp;
        }
        return ans;
    }
};