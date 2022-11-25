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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode* head_odd = head, *tail_odd = head_odd;
        ListNode* head_even = head->next, *tail_even = head_even;

        if (head_even)
            head = head->next->next;
        else
            head = head->next;

        for(int i=1; head != NULL; i++) {
            if (i%2 == 1) {
                tail_odd->next = head;
                tail_odd = head;
            } else {
                tail_even->next = head;
                tail_even = head; 
            }

            head = head->next;
        };

        if (tail_even)
            tail_even->next = NULL;

		tail_odd->next = head_even;

        return head_odd;
    }
};