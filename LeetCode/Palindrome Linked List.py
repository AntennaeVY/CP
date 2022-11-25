# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        node_values = []

        while slow:
            node_values.append(slow.val)
            slow = slow.next

        for i in range(len(node_values)//2 + 1):
            if node_values[i] != node_values[-i-1]:
                return False
        
        return True