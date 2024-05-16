# [160. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

![image-20240516195318969](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516195318969.png)

![image-20240516195329083](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516195329083.png)

![image-20240516195344554](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516195344554.png)

![image-20240516195352386](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516195352386.png)



本题关键在于：

- 如果两个链表长度相同，那么同时开始从头遍历即可
- 如果长度不同，寻找一种方式让两者**走过相同的路径**

本题思路参考题解：

https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/10774/tu-jie-xiang-jiao-lian-biao-by-user7208t

![相交链表.png](https://pic.leetcode-cn.com/e86e947c8b87ac723b9c858cd3834f9a93bcc6c5e884e41117ab803d205ef662-%E7%9B%B8%E4%BA%A4%E9%93%BE%E8%A1%A8.png)

Code：

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        while(h1!=h2){
            h1 = h1==NULL?headB:h1->next;
            h2 = h2==NULL?headA:h2->next;
        }
        return h1;
    }
};
```





