class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        stack = [float('inf')]
        res = 0
        for num in arr:
            while stack and stack[-1] <= num:
                cur = stack.pop()
                if stack:
                    res += cur * min(stack[-1], num)
            stack.append(num)
        while len(stack) > 2:
            res += stack.pop() * stack[-1]
        return res
