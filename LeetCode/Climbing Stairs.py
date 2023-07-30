class Solution:
    def climbStairs(self, n: int) -> int:
        ways = [1,1,2];
        
        for i in range(3, n+1):
            ways.append(ways[-1] + ways[-2])
            
        return ways[n]