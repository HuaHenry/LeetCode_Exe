# [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

![image-20240810154007805](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240810154007805.png)

![image-20240810154021495](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240810154021495.png)

本题的思路很简单，直接进行**中序遍历**即可。因为右边的节点是后遍历到的，所以遍历的过程中进行**替换**即可。注意需要记录深度。

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
    int ans[105];           // 存储实时替换的最右节点
    int max_depth = 0;      // 存储最大深度

    void search(int depth,TreeNode* root){
        // 中序遍历
        if(!root) return;
        max_depth = max(max_depth,depth);
        search(depth+1,root->left);
        ans[depth] = root->val;
        search(depth+1,root->right);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>{};
        search(0,root);
        vector<int> res;
        for(int i=0;i<=max_depth;i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};
```

