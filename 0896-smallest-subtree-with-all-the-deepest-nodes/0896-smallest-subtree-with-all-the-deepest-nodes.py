# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if root == None : return None , 0
            lr , ld = dfs(root.left)
            rr, rd = dfs(root.right)
            if ld > rd : return lr , ld + 1
            elif rd > ld : return rr , rd + 1
            return root , ld + 1
        return dfs(root)[0]