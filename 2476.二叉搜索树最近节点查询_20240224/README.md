# [2476. 二叉搜索树最近节点查询](https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/)



![image-20240224142626608](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240224142626608.png)

![image-20240224142636806](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240224142636806.png)



题目的核心是找到**小于等于特定值的最大值**，和**大于等于特定值的最小值**。

因此先将所有节点值**排序**，后者可以用 `lower_bound` （找到第一个不小于特定值的元素）直接实现，前者需要做一些判断和处理。

具体判断过程见代码。注意 `lower_bound` 找不到就返回最后一个元素后一个元素下标。



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
    vector<int> tree;

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        //中序遍历存储结果
        dfs(root);
        sort(tree.begin(),tree.end());
        //二分查找
        vector<vector<int>> ans;
        for(auto it:queries){
            int pos = lower_bound(tree.begin(),tree.end(),it)-tree.begin();
            int max_number = pos>=tree.size()?-1:tree[pos];
            int min_number = pos>=tree.size()?tree[tree.size()-1]:(tree[pos]==it?tree[pos]:(pos==0?-1:tree[pos-1]));
            vector<int> tmp;
            tmp.push_back(min_number);
            tmp.push_back(max_number);
            ans.push_back(tmp);
        }
        return ans;
    }

    void dfs(TreeNode* node){
        if(!node) return;
        tree.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};
```





