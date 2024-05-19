# [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

![image-20240519161140627](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240519161140627.png)

![image-20240519161150026](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240519161150026.png)



**一趟扫描**实现的方法：**递归**

**回溯过程实现计数 + 节点的删除**。注意首元素的特殊判断，本程序使用**添加额外首节点**的方法避免了该问题。

Code：

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int delNode(ListNode* now,int n){
        if(now==NULL) return 1;
        else{
            int num = delNode(now->next,n);
            if(num==n+1) now->next = ((now->next==NULL)?NULL:now->next->next);
            return num+1;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Nhead = new ListNode;
        Nhead->next = head;
        delNode(Nhead,n);
        return Nhead->next;
    }
};
```

