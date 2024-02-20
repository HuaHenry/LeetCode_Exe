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
    int pre_num = 0;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return check(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode *check(vector<int> &preorder, vector<int> &inorder, int in_left, int in_right)
    {
        TreeNode *newNode = new TreeNode;
        newNode->val = preorder[pre_num++];
        if (in_left != in_right)
        {
            // 需要继续建子树
            // 找到当前元素在inorder中的位置，左右孩子递归建树
            for (int i = in_left; i <= in_right; i++)
            {
                if (inorder[i] == newNode->val)
                {
                    newNode->left = (i == in_left ? NULL : check(preorder, inorder, in_left, i - 1));
                    newNode->right = (i == in_right ? NULL : check(preorder, inorder, i + 1, in_right));
                    break;
                }
            }
        }
        return newNode;
    }
};