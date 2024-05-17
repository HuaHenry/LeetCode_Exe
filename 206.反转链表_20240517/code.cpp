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

    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return NULL;
        reverse(head);
        return res;
    }
};