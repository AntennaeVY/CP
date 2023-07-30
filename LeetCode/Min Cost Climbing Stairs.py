class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        minCostStair = []
        
        minCostStair.append(cost[0])
        minCostStair.append(cost[1])
        
        for i in range(2, len(cost)):
            minCostStair.append(cost[i] + min(minCostStair[i-1], minCostStair[i-2]))
        
        return min(minCostStair[len(cost)-1], minCostStair[len(cost)-2])