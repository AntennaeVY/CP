grid = open("8.in").read().strip().split("\n")

ans = len(grid)*2 + 2*(len(grid[0]) - 2)
highest_score = 0

for i in range(1, len(grid)-1):
    for j in range(1, len(grid[0])-1):
        up, down, left, right = [True]*4
        up_score, down_score, left_score, right_score = [0]*4

        for k in range(i):
            up &= grid[k][j] < grid[i][j]

        for k in range(i-1, -1, -1):
            up_score += 1

            if grid[k][j] >= grid[i][j]:
                break

        for k in range(i+1, len(grid)):
            down &= grid[k][j] < grid[i][j]

        for k in range(i+1, len(grid)):
            down_score += 1

            if grid[k][j] >= grid[i][j]:
                break

        for k in range(j):
            left &= grid[i][k] < grid[i][j]

        for k in range(j-1, -1, -1):
            left_score += 1

            if grid[i][k] >= grid[i][j]:
                break

        for k in range(j+1, len(grid[0])):
            right &= grid[i][k] < grid[i][j]

        for k in range(j+1, len(grid[0])):
            right_score += 1

            if grid[i][k] >= grid[i][j]:
                break

        ans += max(up, down, left, right)
        highest_score = max(highest_score, up_score*down_score*left_score*right_score)


print(ans)
print(highest_score)
