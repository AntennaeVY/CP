file = []

try:
    while line := input():
        file.append(line.strip())
except:
    pass

# Part 1
match = "XMAS"

def dfs(i, j, k, di, dj):
    if i < 0 or i >= len(file):
        return 0

    if j < 0 or j >= len(file[0]):
        return 0

    if match[k] != file[i][j]:
        return 0

    if k == len(match) - 1 and match[k] == file[i][j]:
        return 1

    return dfs(i + di, j + dj, k + 1, di, dj)

ans = 0
directions = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

for i in range(len(file)):
    for j in range(len(file[i])):
        if file[i][j] == 'X':
            for di, dj in directions:
                ans += dfs(i, j, 0, di, dj)

print(ans)

# Part 2
ans = 0
match = "MAS"

for i in range(1, len(file) - 1):
    for j in range(1, len(file[i]) - 1):
        if file[i][j] == 'A':
            d1 = file[i-1][j-1] + file[i][j] + file[i+1][j+1]
            d2 = file[i-1][j+1] + file[i][j] + file[i+1][j-1]

            if (sorted(d1) == sorted(match) and sorted(d2) == sorted(match)):
                ans += 1

print(ans)
