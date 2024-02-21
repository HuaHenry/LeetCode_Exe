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
    int pre_num;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        pre_num = postorder.size() - 1;
        return check(postorder, inorder, 0, postorder.size() - 1);
    }

    TreeNode *check(vector<int> &postorder, vector<int> &inorder, int in_left, int in_right)
    {
        TreeNode *newNode = new TreeNode;
        newNode->val = postorder[pre_num--];
        if (in_left != in_right)
        {
            for (int i = in_left; i <= in_right; i++)
            {
                if (inorder[i] == newNode->val)
                {
                    newNode->right = (i == in_right ? NULL : check(postorder, inorder, i + 1, in_right));
                    newNode->left = (i == in_left ? NULL : check(postorder, inorder, in_left, i - 1));
                    break;
                }
            }
        }
        return newNode;
    }
};