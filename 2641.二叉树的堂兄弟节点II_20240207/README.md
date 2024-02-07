# [2641. 二叉树的堂兄弟节点 II](https://leetcode.cn/problems/cousins-in-binary-tree-ii/)

![image-20240207140658012](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240207140658012.png)

![image-20240207140711060](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240207140711060.png)



思路很简单，就是`bfs`——用一个队列存储一层节点，每个节点替换值为这一层节点的和减自身及其同父兄弟节点的值。



Code：

```c++
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> now_queue = {root};
        root->val = 0;
        while(!now_queue.empty()){
            vector<TreeNode*> temp;
            int sum = 0;
            for(auto i:now_queue){
                //加和
                if(i->left){
                    sum+=i->left->val;
                    temp.push_back(i->left);
                }
                if(i->right){
                    sum+=i->right->val;
                    temp.push_back(i->right);
                }
            }
            //计算节点填充值
            for(auto i:now_queue){
                int t = (i->left?i->left->val:0)+(i->right?i->right->val:0);
                if(i->left){
                    i->left->val = sum-t;
                }
                if(i->right){
                    i->right->val = sum-t;
                }
            }
            //替换队列
            now_queue = move(temp);
        }
        return root;
    }
};
```

