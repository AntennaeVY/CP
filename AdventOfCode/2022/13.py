from functools import cmp_to_key
from pprint import pprint

input = [x.split("\n") for x in open("13.in").read().strip().split("\n\n")]
pairs = [list(map(eval, x)) for x in input]


def compare(a, b):
    if isinstance(a, int) and isinstance(b, int):
        if a < b:
            return -1
        elif a > b:
            return 1
        
        return 0

    if isinstance(a, int) and isinstance(b, list):
        a = [a]

    if isinstance(a, list) and isinstance(b, int):
        b = [b]

    for i in range(min(len(a), len(b))):
        result = compare(a[i], b[i])

        if result != 0:
            return result

    if len(a) == len(b):
        return 0

    return 1 if len(a) > len(b) else -1


ans = 0
for i, pair in enumerate(pairs):
    if compare(pair[0], pair[1]) == -1:
        ans += i+1

print(ans)

all = [y for x in pairs for y in x]
all.append([[2]])
all.append([[6]])

all.sort(key=cmp_to_key(compare))

l1 = all.index([[2]]) + 1
l2 = all.index([[6]]) + 1

pprint(all)
print(l1 * l2)
