import math
import sys
 
sys.setrecursionlimit(10000)
 
 
grid = open("12.in").read().strip().split("\n")
visited = []
cache = []
 
for i in range(len(grid)):
    visited.append([])
    cache.append([])
 
    for j in range(len(grid[0])):
        visited[i].append(False)
        cache[i].append(math.inf)
 
 
def dfs(i, j):
    if visited[i][j]:
        return cache[i][j]
 
    visited[i][j] = True
 
    if grid[i][j] == 'E':
        cache[i][j] = 0
        return 0
 
    src = 'a' if grid[i][j] == 'S' else grid[i][j]
    ans = math.inf
 
    if i > 0:
        dst = 'z' if grid[i-1][j] == 'E' else grid[i-1][j]
 
        if ord(dst) - ord(src) <= 1:
            ans = min(ans, dfs(i-1, j))
 
    if i < len(grid)-1:
        dst = 'z' if grid[i+1][j] == 'E' else grid[i+1][j]
 
        if ord(dst) - ord(src) <= 1:
            ans = min(ans, dfs(i+1, j))
 
    if j > 0:
        dst = 'z' if grid[i][j-1] == 'E' else grid[i][j-1]
 
        if ord(dst) - ord(src) <= 1:
            ans = min(ans, dfs(i, j-1))
 
    if j < len(grid[0])-1:
        dst = 'z' if grid[i][j+1] == 'E' else grid[i][j+1]

        if ord(dst) - ord(src) <= 1:
            ans = min(ans, dfs(i, j+1))

    cache[i][j] = min(cache[i][j], 1 + ans)
    return 1 + ans


for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == 'S':
            print(dfs(i, j))
            break
