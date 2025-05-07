file = []

try:
    while line := input():
        file.append(list(line))

        if file[-1][-1] == '\r':
            file[-1] = file[-1][:-1]

except Exception as e:
    pass

# Part 1
def solve(matrix): 
    file = [row[:] for row in matrix]

    x, y = -1, -1
    n, m = len(file), len(file[0])

    for i in range(n):
        for j in range(m):
            if file[i][j] == '.' or file[i][j] == '#':
              continue

            x, y = i, j

    change = {
        "^": ">",
        ">": "v",
        "v": "<",
        "<": "^"
    }

    direction = {
     "^": (-1, 0),
     ">": (0, 1),
     "v": (1, 0),
     "<": (0, -1)
    }

    ways = [[[] for y in range(m)] for x in range(n)]

    while True:
        dx, dy = direction[file[x][y]]
    
        if x + dx < 0 or x + dx >= n:
            break
    
        if y + dy < 0 or y + dy >= m:
            break
    
        if (file[x][y] in ways[x][y]):
            return -1

        ways[x][y].append(file[x][y])
    
        if file[x+dx][y+dy] == '.' or file[x+dx][y+dy] == 'X':
          file[x+dx][y+dy] = file[x][y]
          file[x][y] = 'X'
         
          x += dx
          y += dy
        elif file[x+dx][y+dy] == '#':
          file[x][y] = change[file[x][y]]
    
    ans = 1 + sum([1 if file[x][y] == 'X' else 0 for x in range(n) for y in range(m)])

    return ans

print(solve(file))
# Part 2

ans = 0
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
n = len(file)
m = len(file[0])

for i in range(n):
    for j in range(m):
        if file[i][j] != '.':
            continue
        
        before = file[i][j]

        file[i][j] = '#'
        result = solve(file)
        file[i][j] = before

        if result == -1:
            ans += 1
        
print(ans)
