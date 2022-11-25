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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* current = head;
        vector<ListNode*> list;

        while(current) {
            list.push_back(current);
            current = current->next;
        }

        sort(list.begin(), list.end(), [](const ListNode* a, const ListNode* b){
            return a->val < b->val;
        });

        for(int i=1; i < list.size(); i++) {
            list[i-1]->next = list[i];
        }

        list[list.size() - 1]->next = NULL;
        return list[0];
    }
};