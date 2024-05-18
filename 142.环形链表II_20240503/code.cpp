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
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodes;
        if (head == NULL || head->next == NULL)
            return NULL;
        while (head != NULL)
        {
            if (nodes.count(head) != 0)
                return head;
            else
                nodes.insert(head);
            head = head->next;
        }
        return NULL;
    }
};