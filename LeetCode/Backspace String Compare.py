class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def buildString(string: str) -> str:
            stack = []
            ans = ""
            
            for ch in string:
                if ch != "#":
                    stack.append(ch)
                elif len(stack) > 0:
                    stack.pop()
            
            for ch in stack:
                ans += ch
            
            return ans
        
        return buildString(s) == buildString(t)
            