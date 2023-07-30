"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def dfs(self, root: 'Node', ans: 'list of nodes') -> None:
        if not root: return None
        
        ans.append(root.val)
        
        for child in root.children:
            self.dfs(child, ans)
    
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        self.dfs(root, ans)
        
        return ans
    