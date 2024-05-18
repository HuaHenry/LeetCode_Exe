# [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

![image-20240518101931498](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518101931498.png)

​	![image-20240518101942631](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518101942631.png)



对于需要精确到具体节点的问题，可以直接使用**哈希表**存储经过的节点，对于每一个遍历到的节点再查找即可。

时间复杂度 $O(nlogn)$，空间复杂度 $O(n)$。



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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        if(head==NULL || head->next==NULL) return NULL;
        while(head!=NULL){
            if(nodes.count(head)!=0) return head;
            else nodes.insert(head);
            head=head->next;
        }
        return NULL;
    }
};
```

题解中给出空间复杂度 $O(1)$ 的解法：`快慢指针`

![image-20240518102212575](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518102212575.png)

经过数学推导，**快慢指针**最终会在**入环点相遇**