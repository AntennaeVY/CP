class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        mapH_N = {}
        
        for i in range(len(names)):
            mapH_N[heights[i]] = names[i]
        
        heights.sort(reverse=True)
        
        sol = []
        
        for i in range(len(heights)):
            sol.append(mapH_N[heights[i]])
            
        return sol
        