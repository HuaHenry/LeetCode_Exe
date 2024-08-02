# [230. 二叉搜索树中第K小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/)

![image-20240802142035202](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240802142035202.png)

![image-20240802142048754](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240802142048754.png)

二叉搜索树的一个重要性质在于：**中序遍历是所有节点的顺序排列**。那么找到第 $k$ 小的元素易如反掌。

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
    int cnt=0, ans=0;

    void findNode(TreeNode* root,int k){
        if(!root) return;
        findNode(root->left,k);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return;
        }
        findNode(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // 二叉搜索树的性质：中序遍历就是所有元素的顺序排列
        findNode(root,k);
        return ans;
    }
};
```

