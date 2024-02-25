# [235. 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)



![image-20240225132022750](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240225132022750.png)

![image-20240225132031243](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240225132031243.png)



注意本题面对的是**二叉搜索树**，所以可以直接从根节点开始遍历，如果两个待查找节点需要在某个节点**开始分离**（往左右两个不同方向查找），那么就说明查找到了。一次遍历即可。



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
        //只需要找到分岔点即可
        TreeNode* ans = root;
        while(true){
            if(p->val<ans->val&&q->val<ans->val) ans = ans->left;
            else if(p->val>ans->val&&q->val>ans->val) ans = ans->right;
            else break;
        }
        return ans;
    }
};
```

