# [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)

![image-20240518101154148](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518101154148.png)

![image-20240518101203429](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518101203429.png)

![image-20240518101211611](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518101211611.png)

本题很明显可以使用**快慢指针**解决（一定会相遇）。需要注意的是，判断指针指到一个位置，初始状态不能参与判断（因为都指向 `head`），也就是本人解法中引入 `cnt` 的原因。题解中解法是预先判断，也可以使用。

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
    bool hasCycle(ListNode *head) {
        // 使用快慢指针 -> 若有环则指针总会相遇
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = 0;
        while(fast!=NULL && fast->next!=NULL){
            if(fast==slow && cnt!=0) return true;
            else if(fast==slow && cnt==0) cnt++;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
```

