import re
import bisect

file = []
while line := input():
    file.append(line)

# Part 1

ans = 0

for line in file:
    for x in re.finditer(r'mul\((\d{1,3},\d{1,3})\)', line):
        a, b = map(int, x[1].split(','))
        ans += a * b

print(ans)

# Part 2
ans = 0

file = ["".join(file).replace('\n', '')]

for line in file:
    do = [-1]
    dont = [-2]
    
    for x in re.finditer(r'do\(\)', line):
        do.append(x.start())
    
    for x in re.finditer(r'don\'t\(\)', line):
        dont.append(x.start())

    for x in re.finditer(r'mul\((\d{1,3},\d{1,3})\)', line):
        a, b = map(int, x[1].split(','))

        i = bisect.bisect(do, x.start()) - 1 
        j = bisect.bisect(dont, x.start()) - 1

        if (do[i] > dont[j]):
            ans += a * b 

print(ans)


