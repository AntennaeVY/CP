# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    state = deque([])

    def in_order_traversal(self, root):
        if not root:
            return None

        self.in_order_traversal(root.left)
        self.state.appendleft(root.val)
        self.in_order_traversal(root.right)

    def __init__(self, root: Optional[TreeNode]):
        self.in_order_traversal(root)
            

    def next(self) -> int:
        return self.state.pop()

    def hasNext(self) -> bool:
        return len(self.state) > 0
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()