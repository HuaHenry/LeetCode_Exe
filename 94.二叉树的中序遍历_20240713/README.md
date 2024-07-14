# [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

![image-20240714213507687](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240714213507687.png)



直观的思路就是递归，将遍历左子树和遍历右子树分别递归，遍历中间值放在中间。

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        //递归做法：
        vector<int> ans_left = inorderTraversal(root->left);
        for(int i=0;i<ans_left.size();i++){
            ans.push_back(ans_left[i]);
        }
        ans.push_back(root->val);
        vector<int> ans_right = inorderTraversal(root->right);
        for(int i=0;i<ans_right.size();i++){
            ans.push_back(ans_right[i]);
        }
        return ans;
    }
};
```

本人对于 vector 的处理较为复杂，其实可以不用这么处理。参考以下官方题解的做法，直接传指针即可：

```cpp
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
```

