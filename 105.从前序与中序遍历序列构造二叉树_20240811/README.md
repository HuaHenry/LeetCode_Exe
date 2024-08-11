# [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

![image-20240811165117091](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240811165117091.png)

![image-20240811165125166](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240811165125166.png)

有了先序遍历和中序遍历构建二叉树很简单：使用先序遍历来**划分**中序遍历即可，递归建树。

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
    int preIndex=0;

    TreeNode* createTree(int inL,int inR,vector<int>& preorder, vector<int>& inorder){
        if(preIndex>preorder.size() || inL>inR) return NULL;
        int root = preorder[preIndex];
        //找到划分位置
        int index = inL;
        for(index;index<=inR;index++){
            if(inorder[index]==root) break;
        }
        if(index>inR) return NULL;
        preIndex++;
        TreeNode* newRoot = new TreeNode(root,createTree(inL,index-1,preorder,inorder),createTree(index+1,inR,preorder,inorder));
        return newRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //思路：用先序遍历来划分中序遍历
        return createTree(0,preorder.size()-1,preorder,inorder);
    }
};
```

