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
    ListNode* middleNode(ListNode* head) {
        ListNode *tail = head, *cpy = head;
        int num = 0;
        
        while(tail) {
            num++;
            tail = tail->next;
        }
        
        for(int i=0; i < (num)/2; i++) {
            cpy = cpy->next;
        }
        
        return cpy;
    }
};