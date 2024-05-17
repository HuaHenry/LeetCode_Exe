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
class Solution
{
public:
    ListNode *res;

    void reverse(ListNode *now)
    {
        if (now->next == NULL || now == NULL)
        {
            res = now;
        }
        else
        {
            reverse(now->next);
            now->next->next = now;
            now->next = NULL;
        }
    }

    bool isPalindrome(ListNode *head)
    {
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

        // 使用快慢指针，反转后半部分
        if (head->next == NULL)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 找到了中间节点为 slow
        // 反转slow
        reverse(slow); // 反转后的链表为res
        ListNode *newhead = head;
        // 遍历查看是否匹配
        while (res != NULL && newhead != NULL)
        {
            if (res->val != newhead->val)
                return false;
            else
            {
                res = res->next;
                newhead = newhead->next;
            }
        }
        return true;
    }
};