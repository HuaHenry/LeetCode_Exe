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
    int delNode(ListNode *now, int n)
    {
        if (now == NULL)
            return 1;
        else
        {
            int num = delNode(now->next, n);
            if (num == n + 1)
                now->next = ((now->next == NULL) ? NULL : now->next->next);
            return num + 1;
        }
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *Nhead = new ListNode;
        Nhead->next = head;
        delNode(Nhead, n);
        return Nhead->next;
    }
};