class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn, mx = prices[0], 0
        
        for i in range(1,len(prices)):
            mn = min(mn, prices[i])
            mx = max(mx, prices[i]-mn)
        
        return mx