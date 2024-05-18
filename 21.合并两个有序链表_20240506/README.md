# [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

![image-20240518233705754](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518233705754.png)

![image-20240518233713912](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240518233713912.png)

本题直接循环判断两个链表的头即可。需要注意的是两个链表中的一个用完的情况。

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* res_head = NULL;
        ListNode* res_now = NULL;
        ListNode* tmp;
        while(h1!=NULL&&h2!=NULL){
            if(h1->val<h2->val){
                tmp = h1;
                h1 = h1->next;
            }
            else{
                tmp = h2;
                h2 = h2->next;
            }
            if(!res_head){
                res_head = tmp;
                res_now = tmp;
            }
            else{
                res_now->next = tmp;
                res_now = res_now->next;
            }
        }
        if(h1!=NULL||h2!=NULL){
            if(h1!=NULL){
                tmp = h1;
            }
            if(h2!=NULL){
                tmp = h2;
            }
            if(!res_head){
                res_head = tmp;
                res_now = tmp;
            }
            else{
                res_now->next = tmp;
                res_now = res_now->next;
            }
        }
        return res_head;
    }
};
```

题解中更好的写法是直接递归 `mergeTwoLists` 函数。