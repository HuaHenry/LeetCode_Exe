# [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

![image-20240517155409929](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240517155409929.png)

错误思路：回文字符串的判断使用**栈**是一种**错误**的思路。当回文链表长度为奇数长度，栈无法识别。

本题思路：

使用快慢指针寻找到**链表中间**位置，并**反转后半个**链表。将反转的后半个链表与前半个链表遍历比较即可。

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

    bool isPalindrome(ListNode* head) {
        // 回文串的判断不能使用stack
        // stack<int> lists;
        // while(head!=NULL){
        //     if(lists.empty()) lists.push(head->val);
        //     else{
        //         if(head->val==lists.top()) lists.pop();
        //         else lists.push(head->val);
        //     }
        //     head = head->next;
        // }
        // return lists.empty();

        //使用快慢指针，反转后半部分
        if(head->next==NULL) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        //找到了中间节点为 slow
        //反转slow 
        reverse(slow);  //反转后的链表为res
        ListNode* newhead = head;
        //遍历查看是否匹配
        while(res!=NULL && newhead!=NULL){
            if(res->val!=newhead->val) return false;
            else{
                res = res->next;
                newhead = newhead->next;
            }
        }
        return true;
    }
};
```

