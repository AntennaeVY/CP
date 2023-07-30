/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *current = head;
        map<ListNode*, bool> visited;
        
        while(current && !visited[current]) {
            visited[current] = true;
            current = current->next;
        }
        
        return current;
    }
};