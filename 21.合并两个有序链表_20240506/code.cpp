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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *h1 = list1;
        ListNode *h2 = list2;
        ListNode *res_head = NULL;
        ListNode *res_now = NULL;
        ListNode *tmp;
        while (h1 != NULL && h2 != NULL)
        {
            if (h1->val < h2->val)
            {
                tmp = h1;
                h1 = h1->next;
            }
            else
            {
                tmp = h2;
                h2 = h2->next;
            }
            if (!res_head)
            {
                res_head = tmp;
                res_now = tmp;
            }
            else
            {
                res_now->next = tmp;
                res_now = res_now->next;
            }
        }
        if (h1 != NULL || h2 != NULL)
        {
            if (h1 != NULL)
            {
                tmp = h1;
            }
            if (h2 != NULL)
            {
                tmp = h2;
            }
            if (!res_head)
            {
                res_head = tmp;
                res_now = tmp;
            }
            else
            {
                res_now->next = tmp;
                res_now = res_now->next;
            }
        }
        return res_head;
    }
};