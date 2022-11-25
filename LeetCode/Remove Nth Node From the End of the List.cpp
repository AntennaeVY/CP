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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head_ref = head;
        int size = 0;

        while(head) {
            head = head->next;
            size++;
        }

        if (size == 1 && n == 1)
            return nullptr;
        
        if (size == n) {
            return head_ref->next;
        }

        head = head_ref;

        for(int i=0; i < size - n - 1; i++) {
            head = head->next;
        }

        ListNode* new_next = head->next->next;
        head->next = new_next;

        return head_ref;
    }
};