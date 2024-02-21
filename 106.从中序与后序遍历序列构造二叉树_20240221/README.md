# [106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)



![image-20240221130600921](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240221130600921.png)



思路和 `105` 题很相似，只不过先序遍历改为了后序遍历。 

思路是相似的，从**后往前遍历后序序列**，并划分中序遍历序列。注意需要先看右子树在看左子树。（自己画棵树就能明白啦）

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

    int pre_num ;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pre_num = postorder.size()-1;
        return check(postorder,inorder,0,postorder.size()-1);
    }

    TreeNode* check(vector<int>& postorder, vector<int>& inorder, int in_left, int in_right){
        TreeNode* newNode = new TreeNode;
        newNode->val = postorder[pre_num--];
        if(in_left!=in_right){
            for(int i=in_left;i<=in_right;i++){
                if(inorder[i]==newNode->val){
                    newNode->right = (i==in_right?NULL:check(postorder,inorder,i+1,in_right));
                    newNode->left = (i==in_left?NULL:check(postorder,inorder,in_left,i-1));
                    break;
                }
            }
            
        }
        return newNode;
    }
};
```

