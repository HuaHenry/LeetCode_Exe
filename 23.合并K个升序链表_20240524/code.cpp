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
    struct status {
        int val;
        ListNode *ptr;
        bool operator < (const status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i=0;i<lists.size();i++) {
            ListNode* node = lists[i];
            if (node){
                q.push({node->val, node});
            }
        }

        ListNode head, *tail = &head;

        while (!q.empty()) {
            auto tmp = q.top(); 
            q.pop();
            tail->next = tmp.ptr;
            tail = tail->next;
            if (tmp.ptr->next)
                q.push({tmp.ptr->next->val, tmp.ptr->next});
        }
        return head.next;
    }
};