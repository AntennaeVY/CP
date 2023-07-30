# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bfs(self, root):
        ans = []
        queue = [root]
        
        if (not root): return ans
        
        while(len(queue) > 0):
            level = []
            
            for i in range(len(queue)):
                current = queue.pop(0)
                level.append(current.val)
                
                if(current.left):
                    queue.append(current.left)
                
                if(current.right):
                    queue.append(current.right)
                    
            ans.append(level)
        
        return ans
        
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        return self.bfs(root)
        