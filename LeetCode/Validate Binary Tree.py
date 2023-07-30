# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root: 
            return True
        
        stack = []
        node = root
        prev = None
        
        while (node != None or len(stack) > 0):
            while(node != None):
                stack.append(node)
                node = node.left
                
            node = stack.pop()
                
            if (prev != None and prev.val >= node.val):
                return False
            
            prev = node
            node = node.right
        
        return True
            