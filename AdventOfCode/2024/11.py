from functools import cache

file = []
try:
    while line := input():
        if line[-1] == '\r': 
            file.append(list(map(int, line[:-1].split(' '))))
        else:
            file.append(list(map(int, line.split(' '))))
except:
    pass

line = file[0]

@cache
def dp(x,a):
    if a==0:
        return 1
    if x==0:
        return dp(1,a-1)
    elif len(str(x))%2==0:
        v = str(x)
        return dp((int(v[:len(v)//2])),a-1)+dp(int(v[len(v)//2:]),a-1)
    else:
        return dp(x*2024,a-1)

# Part 1
ans = 0
for x in line:
    ans += dp(x, 25)

print(ans)

# Part 2
ans = 0
for x in line:
    ans += dp(x, 75)

print(ans)
