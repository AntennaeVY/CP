# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        hare = tortoise = head
        
        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next
            
            if (hare == tortoise):
                break
            
        if (not hare or not hare.next):
            return None
        
        tortoise = head
        
        while (hare != tortoise):
            hare = hare.next
            tortoise = tortoise.next
        
        return tortoise
    
        