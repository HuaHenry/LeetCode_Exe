# [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

![image-20240519162458921](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240519162458921.png)

![image-20240519162505979](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240519162505979.png)



本题也是可以新增一个头节点，接着**一趟遍历**即可，非常简单。思路直接见代码。



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
    ListNode* swapPairs(ListNode* head) {
        ListNode* Nhead = new ListNode;
        Nhead->next = head;
        ListNode* tmp = Nhead;
        while(tmp!=NULL){
            ListNode* node1 = tmp->next;
            if(node1==NULL) break;
            ListNode* node2 = tmp->next->next;
            if(node2==NULL) break;
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        return Nhead->next;
    }
};
```







