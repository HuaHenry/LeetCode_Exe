# [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

![image-20240802135308051](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240802135308051.png)

![image-20240802135317091](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240802135317091.png)

本题最直观的想法是使用**递归**进行判断。但是需要注意的是二叉搜索树为了实现搜索，要求**左子树所有元素小于root、右子树所有元素大于root**。这就需要在递归的同时维护一个左边界和一个右边界。

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
    // 重点：子树所有元素对于root的判断
    bool checkTree(TreeNode* root,long long int l,long long int r){
        // 递归解决问题
        if(!root) return true;
        if(root->left && (root->val<=root->left->val || !(root->left->val>l && root->left->val<r))) return false;
        if(root->right && (root->val>=root->right->val || !(root->right->val>l && root->right->val<r))) return false;
        if(checkTree(root->left,l,root->val) && checkTree(root->right,root->val,r) && root->val<r && root->val>l) return true;
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return checkTree(root,-21474836480,21474836470);
    }
};
```

官方题解的递归较为简略：

```cpp
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
```

