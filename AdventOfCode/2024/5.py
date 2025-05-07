rules = []
lines = []

try:
    while line := input():
        clean = line.replace('\n', '').replace('\r', '').split('|')

        if (clean[0] == ''):
            break
        
        rules.append(list(map(int, clean)))

    while line := input():
        lines.append(list(map(int, line.split(','))))

except Exception as e: 
    #print(e)
    pass


# Part 1
depends = [[] for _ in range(100)]

for a,b in rules:
    depends[b].append(a)

ans = 0
invalids = []

for line in lines:
    seen = [False] * 100
    invalid = False
    
    for x in line:
        seen[x] = True
        invalid |= any(not seen[y] and y in line for y in depends[x])

    if not invalid:
        ans += line[len(line)//2]
    else:
        invalids.append(line)


print(ans)
    
# Part 2

ans = 0

for line in invalids:
    newline = []

    seen = [False] * 100
    
    for _ in line:
        for x in line:
            invalid = any(not seen[y] and y in line for y in depends[x])

            if not invalid and not seen[x]:
                seen[x] = True
                newline.append(x)

    ans += newline[len(newline)//2]

print(ans)
