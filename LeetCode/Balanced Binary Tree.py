# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def get_balanced_height(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        left_height = self.get_balanced_height(root.left)
        right_height = self.get_balanced_height(root.right)

        if left_height == -1 or right_height == -1:
            return -1

        if abs(left_height - right_height) > 1:
            return -1

        return max(left_height, right_height) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if self.get_balanced_height(root) == -1:
            return False
        else:
            return True
        