# [889. 根据前序和后序遍历构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)



![image-20240222135606823](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240222135606823.png)

![image-20240222135616306](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240222135616306.png)



现在已知先序和后序遍历。可以发现一个特点——**先序遍历中的一个元素 = 后序遍历中的最后一个元素 = 根节点**。这对于子树也成立，因此可以使用**分治**的方法，分治处理左子树和右子树。

其中，如果某个节点只有左子树或只有右子树，都可以归为只有左子树的情况，因为不影响先序 / 后序遍历序列。



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
// class Solution {
// public:

//     int cnt = 0;    //记录 preorder 的遍历位置
//     unordered_map<int,int> post_map;

//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//         //构建 postorder 的后序哈希映射
//         for(int i=0;i<postorder.size();i++){
//             post_map[postorder[i]] = i;
//         }
//         TreeNode* root = new TreeNode(preorder[cnt++]);
//         int right_end = 0;
//         root->left = func(preorder,postorder,0,postorder.size()-2,right_end);
//         root->right = func(preorder,postorder,0,postorder.size()-2,right_end);
//         return root;
//     }

//     TreeNode* func(vector<int>& preorder, vector<int>& postorder,int left_post,int right_post,int& right_end){
//         cout<<left_post<<' '<<right_post<<endl;
//         if(left_post>right_post||cnt>=preorder.size()) return NULL;
//         if(left_post==right_post) return (new TreeNode(preorder[cnt++]));
//         //分治划分
//         TreeNode* tmp = new TreeNode(preorder[cnt++]);
//         right_end = post_map[tmp->val];
//         tmp->left = func(preorder,postorder,left_post,right_end);
//         tmp->right = func(preorder,postorder,right_end+1,right_post);
//         return tmp;
//     }
// };

class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        int n = preorder.size();
        unordered_map<int, int> postMap;

        //构建哈希映射
        for (int i = 0; i < n; i++) {
            postMap[postorder[i]] = i;
        }

        function<TreeNode *(int, int, int, int)> dfs = [&](int preLeft, int preRight, int postLeft, int postRight) -> TreeNode * {
            if (preLeft > preRight) {
                return nullptr;
            }
            int leftCount = 0;
            if (preLeft < preRight) {
                leftCount = postMap[preorder[preLeft + 1]] - postLeft + 1;
            }
            return new TreeNode(preorder[preLeft],
                dfs(preLeft + 1, preLeft + leftCount, postLeft, postLeft + leftCount - 1),
                dfs(preLeft + leftCount + 1, preRight, postLeft + leftCount, postRight - 1));
        };

        return dfs(0, n - 1, 0, n - 1);
    }
};
```

