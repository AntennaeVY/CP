class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones_neg = [-x for x in stones]
        
        heapq.heapify(stones_neg)
        
        while len(stones_neg) > 1:
            first = heapq.heappop(stones_neg)
            second = heapq.heappop(stones_neg)
            
            if first != second:
                heapq.heappush(stones_neg, first - second)
        
        if len(stones_neg) > 0:
            return -1*stones_neg[0]
        else:
            return 0