# [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

![image-20240714220034413](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240714220034413.png)

![image-20240714220047505](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240714220047505.png)

本质就是递归实现，如果到叶子节点那么长度设为0，不断返回时增加长度并判断即可。

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

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
    }
};
```

看讨论似乎用三目运算符更快一点，可以尝试改进。