# [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)



![image-20240220110316508](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240220110316508.png)

![image-20240220110332191](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240220110332191.png)



给定了中序遍历和先序遍历，可以发现：

- 先序遍历的特点在于子树根节点在子树序列的**最前面**
- 中序遍历的特点在于子树根节点在子树序列**中间**，且左边是左子树，右边是右子树

所以可以**按顺序遍历先序遍历序列**，同时**找到中序序列中的对应元素**，**划分左右子树**，就实现了树的建立。



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

    int pre_num = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return check(preorder,inorder,0,inorder.size()-1);
    }

    TreeNode* check(vector<int>& preorder, vector<int>& inorder, int in_left, int in_right){
        TreeNode* newNode = new TreeNode;
        newNode->val = preorder[pre_num++];
        if(in_left!=in_right){
            //需要继续建子树
            //找到当前元素在inorder中的位置，左右孩子递归建树
            for(int i=in_left;i<=in_right;i++){
                if(inorder[i]==newNode->val){
                    newNode->left = (i==in_left?NULL:check(preorder,inorder,in_left,i-1));
                    newNode->right = (i==in_right?NULL:check(preorder,inorder,i+1,in_right));
                    break;
                }
            }
            
        }
        return newNode;
    }
};
```



AC后参考题解，上述遍历找到中序序列中对应元素位置的方法可以改进为**哈希映射**：

![image-20240220110854364](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240220110854364.png)