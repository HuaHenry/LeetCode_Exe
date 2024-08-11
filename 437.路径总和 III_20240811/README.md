# [437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii/)

![image-20240811170724035](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240811170724035.png)

![image-20240811170751401](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240811170751401.png)

思路是dfs暴力搜索，对于**每一个节点作为上节点**实现一遍搜索。搜索过程中使用递归，具体思路见代码。

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
    int findNum(TreeNode* root, long long int targetSum){
        if(!root) return 0;
        // cout<<root->val<<' '<<targetSum<<endl;
        return (root->val==targetSum?1:0)+findNum(root->left,targetSum-root->val)+findNum(root->right,targetSum-root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        //思路：dfs爆搜，注意不要剪枝
        if(!root) return 0;
        return findNum(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};
```

