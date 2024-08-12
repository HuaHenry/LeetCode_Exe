# [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/)

![image-20240812131141214](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240812131141214.png)

![image-20240812131156811](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240812131156811.png)

本题的思路是对于某一个节点，计算以它为根的子树的最大路径和，因此可以不断**递归**。注意向上返回时，需要取左子树和右子树中的**最大路径**。

Code：

```cpp
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
class Solution {
public:
    //维护记录最大路径和
    int res = INT_MIN;

    int maxSum(TreeNode* root) {
        if(!root) return 0;
        //递归计算左右节点
        int left = max(maxSum(root->left),0);
        int right = max(maxSum(root->right),0);
        res = max(res,left+right+root->val);
        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return res;
    }
};
```

