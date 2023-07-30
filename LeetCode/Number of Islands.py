class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = [[False for _ in range(len(grid[0]))] for __ in range(len(grid))]
        ans = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if visited[i][j] or grid[i][j] == '0':
                    continue
                
                self.dfs(i, j, grid, visited)
                ans += 1
        
        return ans
                
    
    def dfs(self, i: int, j: int, grid: List[List[str]], visited: List[List[bool]]) -> None:
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
            return None
        
        if visited[i][j] or grid[i][j] == '0':
            return None
        
        visited[i][j] = True
        
        self.dfs(i+1, j, grid, visited)
        self.dfs(i-1, j, grid, visited)
        self.dfs(i, j+1, grid, visited)
        self.dfs(i, j-1, grid, visited)