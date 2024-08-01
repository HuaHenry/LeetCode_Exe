# [108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

![image-20240801224542703](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240801224542703.png)

![image-20240801224553585](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240801224553585.png)

**折半法**可以直接处理二叉搜索树的生成。具体思路见代码。

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
    TreeNode* makeTree(vector<int>& nums,int l,int r){
        if(l>r) return NULL;
        int midIndex = (l+r)/2;
        TreeNode* rootNode = new TreeNode;
        rootNode->val = nums[midIndex];
        rootNode->left = makeTree(nums,l,midIndex-1);
        rootNode->right = makeTree(nums,midIndex+1,r);
        return rootNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums,0,nums.size()-1);
    }
};
```

