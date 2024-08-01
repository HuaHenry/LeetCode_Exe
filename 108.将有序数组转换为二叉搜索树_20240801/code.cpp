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
    TreeNode *makeTree(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int midIndex = (l + r) / 2;
        TreeNode *rootNode = new TreeNode;
        rootNode->val = nums[midIndex];
        rootNode->left = makeTree(nums, l, midIndex - 1);
        rootNode->right = makeTree(nums, midIndex + 1, r);
        return rootNode;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeTree(nums, 0, nums.size() - 1);
    }
};