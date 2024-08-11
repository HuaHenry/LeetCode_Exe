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
    int preIndex = 0;

    TreeNode *createTree(int inL, int inR, vector<int> &preorder, vector<int> &inorder)
    {
        if (preIndex > preorder.size() || inL > inR)
            return NULL;
        int root = preorder[preIndex];
        // 找到划分位置
        int index = inL;
        for (index; index <= inR; index++)
        {
            if (inorder[index] == root)
                break;
        }
        if (index > inR)
            return NULL;
        preIndex++;
        TreeNode *newRoot = new TreeNode(root, createTree(inL, index - 1, preorder, inorder), createTree(index + 1, inR, preorder, inorder));
        return newRoot;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 思路：用先序遍历来划分中序遍历
        return createTree(0, preorder.size() - 1, preorder, inorder);
    }
};