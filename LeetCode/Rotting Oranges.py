class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        visited = set()
        m = len(grid[0])
        n = len(grid)

        ans = 0

        while True:
            to_rotten = []

            for i in range(len(grid)):
                for j in range(len(grid[i])):
                    if grid[i][j] == 2 and tuple([i,j]) not in visited:
                        if i > 0 and grid[i-1][j] == 1:
                            to_rotten.append(tuple([i-1, j]))
                        
                        if i < n-1 and grid[i+1][j] == 1:
                            to_rotten.append(tuple([i+1, j]))

                        if j > 0 and grid[i][j-1] == 1:
                            to_rotten.append(tuple([i, j-1]))

                        if j < m-1 and grid[i][j+1] == 1:
                            to_rotten.append(tuple([i, j+1]))

                    if grid[i][j] != 1:
                        visited.add(tuple([i,j]))
            
            if len(to_rotten) == 0:
                break

            for orange in to_rotten:
                grid[orange[0]][orange[1]] = 2

            ans += 1

        if len(visited) < n*m:
            ans = -1

        return ans