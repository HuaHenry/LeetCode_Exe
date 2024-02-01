# 2.两数相加



<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240201170429257.png" alt="image-20240201170429257" style="zoom:50%;" />

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240201170444921.png" alt="image-20240201170444921" style="zoom:50%;" />


题目将数字**逆序存放**，所以可以直接从两个链表的头开始对应元素相加，并使用一个变量记录进位。

链表操作，可以设置一个预取节点`preNode`用于指向第一个节点，后续操作更方便

Code：

```c++
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *preNode = new ListNode(-1);
        ListNode *nowNode = preNode;
        bool flag=false;
        while(true){
            // 处理逐元素相加
            if(l1==NULL&&l2==NULL) break;
            int newNumber=(l1==NULL?0:l1->val)+(l2==NULL?0:l2->val)+(flag);
            flag = newNumber>=10;
            nowNode->next = new ListNode(newNumber%10);
            nowNode = nowNode->next;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(flag) nowNode->next = new ListNode(1);

        return preNode->next;
    }
};
```

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240201170710253.png" alt="image-20240201170710253" style="zoom:50%;" />



