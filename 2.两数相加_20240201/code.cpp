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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *preNode = new ListNode(-1);
        ListNode *nowNode = preNode;
        bool flag = false;
        while (true)
        {
            // 处理逐元素相加
            if (l1 == NULL && l2 == NULL)
                break;
            int newNumber = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + (flag);
            flag = newNumber >= 10;
            nowNode->next = new ListNode(newNumber % 10);
            nowNode = nowNode->next;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        if (flag)
            nowNode->next = new ListNode(1);

        return preNode->next;
    }
};