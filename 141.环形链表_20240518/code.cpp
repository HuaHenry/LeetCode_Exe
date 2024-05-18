/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // 使用快慢指针 -> 若有环则指针总会相遇
        ListNode *fast = head;
        ListNode *slow = head;
        int cnt = 0;
        while (fast != NULL && fast->next != NULL)
        {
            if (fast == slow && cnt != 0)
                return true;
            else if (fast == slow && cnt == 0)
                cnt++;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};