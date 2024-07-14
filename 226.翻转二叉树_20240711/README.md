# [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

![image-20240714220818398](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240714220818398.png)

![image-20240714220917173](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240714220917173.png)

需要翻转的主要内容为：

- 左子树内部翻转
- 右子树内部翻转
- 左右root交换

即可以使用递归实现。

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
    TreeNode* invertTree(TreeNode* root) {
        //思路：递归
        if(!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};
```

