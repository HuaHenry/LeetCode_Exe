# [938. 二叉搜索树的范围和](https://leetcode.cn/problems/range-sum-of-bst/)



![image-20240226175557915](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240226175557915.png)

![image-20240226175613305](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240226175613305.png)



很简单的一道题，只需要**遍历二叉树**并**判断节点值**即可。



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

    int ans = 0;

    void dfs(TreeNode* nowNode,int low,int high){
        if(!nowNode) return;
        if(nowNode->val>=low && nowNode->val<=high){
            ans += nowNode->val;
        }
        dfs(nowNode->left,low,high);
        dfs(nowNode->right,low,high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        ///遍历并判断即可
        dfs(root,low,high);
        return ans;
    }
};
```

