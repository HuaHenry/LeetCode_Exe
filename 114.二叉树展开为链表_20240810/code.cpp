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
    TreeNode *nowEnd;

    void findNode(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *newNode = new TreeNode(root->val, NULL, NULL);
        nowEnd->right = newNode;
        nowEnd->left = NULL;
        nowEnd = newNode;
        findNode(root->left);
        findNode(root->right);
    }

    void flatten(TreeNode *root)
    {
        // 创建新的头节点
        TreeNode *newHead = new TreeNode;
        if (!root)
            return;
        nowEnd = newHead;
        findNode(root);
        root->right = newHead->right->right;
        root->left = NULL;
    }
};