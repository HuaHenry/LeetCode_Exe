# [102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

![image-20240801222359230](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240801222359230.png)

![image-20240801223335893](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240801223335893.png)

二叉树的层次遍历常用方法：使用**队列**，存储一层的节点。头部出一个节点同时在尾部加入这个节点的左孩子和右孩子即可。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qNode;
        qNode.push(root);
        while(!(qNode.empty())){
            vector<int> tmp;
            queue<TreeNode*> nodetmp;
            while(!(qNode.empty())){
                TreeNode* now = qNode.front();
                qNode.pop();
                if(now){
                    tmp.push_back(now->val);
                    if(now->left) nodetmp.push(now->left);
                    if(now->right) nodetmp.push(now->right);
                }
            }
            if(tmp.size()!=0) ans.push_back(tmp);
            qNode = nodetmp;
        }
        return ans;
    }
};
```

