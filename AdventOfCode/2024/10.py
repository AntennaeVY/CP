file = []

try:
    while line := input():
        file.append(list(map(int, list(line))))

        if file[-1][-1] == '\r':
            file[-1] = file[-1][:-1]
except Exception as e:
    pass

n = len(file)
m = len(file[0])

d = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def dfs(x, y, i, j, st):
    global file

    if i < 0 or i >= n:
        return 0

    if j < 0 or j >= m:
        return 0

    if x != -1 and y != -1 and file[i][j] != file[x][y] + 1:
        return 0

    if file[i][j] == 9:
        st.add((i,j))
        return 1

    ans = 0
    
    for dx, dy in d:
        ans += dfs(i, j, i + dx, j + dy, st)

    return ans

# Part 1
ans = 0
ans2 = 0

for i in range(n):
    for j in range(m):
        if file[i][j] != 0:
            continue
        st = set()
        
        # Part 2 lol
        ans2 += dfs(-1, -1, i, j, st)
        ans += len(st)

print(ans)
print(ans2)
