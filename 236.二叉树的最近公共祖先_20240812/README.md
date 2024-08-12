# [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

![image-20240812114305890](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240812114305890.png)

![image-20240812114319132](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240812114319132.png)

本题通过观察，可以看到很重要的一点：如果最近公共祖先不是自己，那么两个节点一定分布在其左右两侧。否则就分布在一侧，可以继续查找。

因此可以设计递归算法如下。

Code：

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //看根节点
        if(!root||root==p||root==q) return root;
        //进一步找更近的祖先
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(!left) return right;
        if(!right) return left;
        //分布在两边，说明当前就是最近的祖先节点
        return root;
    }
};
```

