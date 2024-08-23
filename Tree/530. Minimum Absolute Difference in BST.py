class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.prev = -float("inf")
        self.min_diff = float("inf")
        
        def inorder(troot):
            if not troot:
                return
            inorder(troot.left)
            self.min_diff = min(self.min_diff, troot.val - self.prev)
            self.prev = troot.val
            inorder(troot.right)
        
        inorder(root)
        return self.min_diff
