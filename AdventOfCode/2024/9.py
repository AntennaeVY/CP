file = []
try:
    while line := input():
        if line[-1] == '\r': 
            file.append(list(line)[:-1])
        else:
            file.append(list(line))
except:
    pass

line = file[0]
expanded = []

for i in range(len(line)):
    size = ord(line[i]) - ord('0')

    if i % 2 == 0:
        id = i // 2
        expanded += [str(id)] * size
    else:
        expanded += ['.'] * size

# Part 1
def part1(expanded):
    l, r = 0, len(expanded) - 1

    while l < r:
        while l < r and expanded[r] == '.':
            r -= 1

        while l < r and expanded[l] != '.':
            l += 1

        if l < r:
            expanded[l] = expanded[r]
            expanded[r] = '.'

def checksum(expanded, skip = False):
    ans = 0

    for i in range(len(expanded)):
        if expanded[i] == '.':
            if skip:
                continue
            else:
                break

        ans += int(expanded[i]) * i

    print(ans)

expanded_1 = expanded[::]
part1(expanded_1)
checksum(expanded_1)

# Part 2
def part2(expanded, line):
    line = line[::2]

    for i in range(len(line)-1, -1, -1):
        size = int(line[i]) 

        first = -1 

        for j in range(len(expanded)):
            if expanded[j] == str(i):
                first = j
                break

        for j in range(min(len(expanded) - size + 1, first + 1)):
            if "".join(expanded[j:(j + size)]) == '.' * size:
                # Delete

                for k in range(len(expanded)):
                    if expanded[k] == str(i):
                        expanded[k] = '.'

                # Fill
                for k in range(j, j+size):
                    expanded[k] = str(i)

                break

expanded_2 = expanded[::]
part2(expanded_2, line)
checksum(expanded_2, True)
