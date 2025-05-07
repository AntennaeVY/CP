file = []
while line := input():
    file.append(line)

# Part 1
ans = 0 

for line in file:
    inc = True
    dec = True
    max_diff = 0

    a = list(map(int, line.split(" ")))

    for i in range(1, len(a)):
        inc &= (a[i-1] < a[i])
        dec &= (a[i] < a[i-1])
        max_diff = max(max_diff, abs(a[i] - a[i-1]))

    if (inc or dec) and max_diff <= 3: 
        ans += 1

print(ans)

# Part 2
ans = 0 

for line in file:
    b = list(map(int, line.split(" ")))
    ok = False
    
    for j in range(0, len(b)):
        a = b[0:j] + b[j+1:] 
        
        inc = True
        dec = True
        max_diff = 0

        for i in range(1, len(a)):
            inc &= (a[i-1] < a[i])
            dec &= (a[i] < a[i-1])
            max_diff = max(max_diff, abs(a[i] - a[i-1]))

        if (inc or dec) and max_diff <= 3: 
            ok |= True

    if ok:
        ans += 1

print(ans)


