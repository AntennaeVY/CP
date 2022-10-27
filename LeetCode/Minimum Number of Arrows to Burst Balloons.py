class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        
        lastArrow = points[0][1]
        ans = 1
        
        for i in range(1, len(points)):
            if points[i][0] > lastArrow:
                ans+=1
                lastArrow = points[i][1]
    
        return ans
            