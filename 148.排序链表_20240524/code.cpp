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

    static bool cmp(ListNode* h1, ListNode* h2) {
        return h1->val < h2->val;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        vector<ListNode*> lists;
        ListNode* tmp = head;
        while(tmp!=NULL){
            lists.push_back(tmp);
            tmp = tmp->next;
        }
        sort(lists.begin(),lists.end(),cmp);
        for(int i=0;i<lists.size()-1;i++){
            lists[i]->next = lists[i+1];
        }
        lists[lists.size()-1]->next = NULL;
        return lists[0];
    }
};