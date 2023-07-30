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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newList = new ListNode, *head = new ListNode;
        newList->val = -200;
        head = newList;
        
        while(list1 && list2) {
            if (list1->val < list2->val) {
                newList->next = list1;
                list1 = list1->next;
                newList = newList->next;
            } else {
                newList->next = list2;
                list2 = list2->next;
                newList = newList->next;
            }
        }
        
        while (list1) {
            newList->next = list1;
            list1 = list1->next;
            newList = newList->next;
        }
        
        while(list2) {
            newList->next = list2;
            list2 = list2->next;
            newList = newList->next;
        }
        
        return head->next;
    }
};