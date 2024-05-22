# [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

![image-20240522144319330](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240522144319330.png)

![image-20240522144328165](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240522144328165.png)

实现了使用 $O(1)$ 的额外内存空间解决该问题，每次提取每组第一个节点，使用翻转函数操作即可。需要注意的是还需要处理前后的连接。

具体详见题解，思路一致。

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

    //链表翻转
    pair<ListNode*,ListNode*> reverseList(ListNode* now, ListNode* tail){
        ListNode* i = tail->next;
        ListNode* tmp = now;
        while(i!=tail){
            ListNode* nex = tmp->next;
            tmp->next = i;
            i = tmp;
            tmp = nex;
        }
        return {tail,now};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* Nhead = new ListNode(0,head);
        ListNode* pre = Nhead;
        //开始遍历每组的开始节点
        ListNode* tmp = head;
        while(tmp){
            ListNode* tail = pre;
            //检查原链表余量
            for(int i=0;i<k;i++){
                tail = tail->next;
                if(tail==NULL) return Nhead->next;
            }
            ListNode* nex = tail->next;
            //余量充足，执行翻转
            tie(head,tail)=reverseList(head,tail);
            //重新连接链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return Nhead->next;
    }
};
```

