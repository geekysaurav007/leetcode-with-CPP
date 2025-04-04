# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if root == None : return 0
            return 1 + max(dfs(root.left) , dfs(root.right))
        def solve(root , depth , maxi):
            if root == None : return None
            if depth == maxi - 1:return root
            left = solve(root.left , depth + 1 , maxi)
            right = solve(root.right , depth + 1 , maxi)
            if left != None and right != None : return root
            if left != None : return left
            else : return right
        
        maxi = dfs(root)
        return solve(root , 0 , maxi)
