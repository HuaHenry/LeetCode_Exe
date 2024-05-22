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
    // 链表翻转
    pair<ListNode *, ListNode *> reverseList(ListNode *now, ListNode *tail)
    {
        ListNode *i = tail->next;
        ListNode *tmp = now;
        while (i != tail)
        {
            ListNode *nex = tmp->next;
            tmp->next = i;
            i = tmp;
            tmp = nex;
        }
        return {tail, now};
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *Nhead = new ListNode(0, head);
        ListNode *pre = Nhead;
        // 开始遍历每组的开始节点
        ListNode *tmp = head;
        while (tmp)
        {
            ListNode *tail = pre;
            // 检查原链表余量
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (tail == NULL)
                    return Nhead->next;
            }
            ListNode *nex = tail->next;
            // 余量充足，执行翻转
            tie(head, tail) = reverseList(head, tail);
            // 重新连接链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return Nhead->next;
    }
};