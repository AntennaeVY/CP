# PART 1

with open("3.in") as file:
    sum1 = 0

    matrix = [line.replace("\n", "") for line in file]

    n, m = len(matrix), len(matrix[0])

    for i in range(0, n):
        for j in range(0, m):

            if matrix[i][j] == '.' or matrix[i][j].isdigit():
                continue

            for x, y in [(i-1, j), (i-1, j+1), (i, j+1), (i+1, j+1), (i+1, j), (i+1, j-1), (i, j-1), (i-1, j-1)]:
                if i < 0 or i >= n or j < 0 or j >= m:
                    continue

                l = r = y

                if matrix[x][y].isdigit():
                    while l >= 0 and matrix[x][l].isdigit():
                        l -= 1 
                    
                    while r < m and matrix[x][r].isdigit():
                        r += 1 

                    num = matrix[x][l+1:r]
                    matrix[x] = matrix[x][0:l+1] + '.'*len(num) + matrix[x][r:m]

                    sum1 += int(num)

    print(sum1)

# PART 2

with open("3.in") as file:
    sum2 = 0

    matrix = [line.replace("\n", "") for line in file]

    n, m = len(matrix), len(matrix[0])

    for i in range(0, n):
        for j in range(0, m):

            if matrix[i][j] != '*': 
                continue

            adjacent = 0
            product = 1

            for x, y in [(i-1, j), (i-1, j+1), (i, j+1), (i+1, j+1), (i+1, j), (i+1, j-1), (i, j-1), (i-1, j-1)]:
                if i < 0 or i >= n or j < 0 or j >= m:
                    continue

                l = r = y

                if matrix[x][y].isdigit():
                    while l >= 0 and matrix[x][l].isdigit():
                        l -= 1 
                    
                    while r < m and matrix[x][r].isdigit():
                        r += 1 

                    num = matrix[x][l+1:r]
                    
                    adjacent += 1 
                    product *= int(num)

                    # This doesn't count overlap of two gears
                    matrix[x] = matrix[x][0:l+1] + '.'*len(num) + matrix[x][r:m]


            if adjacent == 2:
                sum2 += product

    print(sum2)

