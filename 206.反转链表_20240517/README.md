# [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

![image-20240517152751247](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240517152751247.png)

![image-20240517152804243](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240517152804243.png)

![image-20240517152811173](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240517152811173.png)

本题可以使用**原地算法**实现链表的反转，本人采取的是递归的执行方式。在递归**执行后返回时**将下一个节点的next指向前一个节点即可。

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
    ListNode* res;

    void reverse(ListNode* now){
        if(now->next==NULL || now == NULL){
            res = now;
        }
        else{
            reverse(now->next);
            now->next->next = now;
            now->next = NULL;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        reverse(head);
        return res;
    }
};
```

