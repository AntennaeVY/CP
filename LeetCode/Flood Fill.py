class Solution:  
    def dfs(self, image, sr, sc, color, match):
        if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]) or image[sr][sc] == color or image[sr][sc] != match:
            return
        
        image[sr][sc] = color
        
        self.dfs(image, sr-1, sc, color, match)
        self.dfs(image, sr+1, sc, color, match)
        self.dfs(image, sr, sc-1, color, match)
        self.dfs(image, sr, sc+1, color, match)
        
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        self.dfs(image, sr, sc, color, image[sr][sc])
        
        return image