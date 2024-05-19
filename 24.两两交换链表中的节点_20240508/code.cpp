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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *Nhead = new ListNode;
        Nhead->next = head;
        ListNode *tmp = Nhead;
        while (tmp != NULL)
        {
            ListNode *node1 = tmp->next;
            if (node1 == NULL)
                break;
            ListNode *node2 = tmp->next->next;
            if (node2 == NULL)
                break;
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        return Nhead->next;
    }
};