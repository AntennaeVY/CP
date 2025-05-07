a = []
b = []

while line := input():
    x, y = map(int, line.split('   '))
    a.append(x)
    b.append(y)

a.sort()
b.sort()

# Part 1

ans = 0

for i in range(len(a)):
    ans += abs(a[i] - b[i])

print(ans)

# Part 2

ans = 0
cnt_a = {}
cnt_b = {}

for x in a:
    cnt_a[x] = cnt_a.get(x, 0) + 1

for x in b:
    cnt_b[x] = cnt_b.get(x, 0) + 1

for k in cnt_a.keys():
    ans += k * cnt_b.get(k, 0)

print(ans)
