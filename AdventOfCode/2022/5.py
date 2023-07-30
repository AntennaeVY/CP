import copy

input = open("5.in").read().strip().split("\n")

#     [G]         [P]         [M]    
#     [V]     [M] [W] [S]     [Q]    
#     [N]     [N] [G] [H]     [T] [F]
#     [J]     [W] [V] [Q] [W] [F] [P]
# [C] [H]     [T] [T] [G] [B] [Z] [B]
# [S] [W] [S] [L] [F] [B] [P] [C] [H]
# [G] [M] [Q] [S] [Z] [T] [J] [D] [S]
# [B] [T] [M] [B] [J] [C] [T] [G] [N]
#  1   2   3   4   5   6   7   8   9

crates = [
    ['B', 'G', 'S', 'C'],
    ['T', 'M', 'W', 'H', 'J', 'N', 'V', 'G'],
    ['M', 'Q', 'S'],
    ['B', 'S', 'L', 'T', 'W', 'N', 'M'],
    ['J', 'Z', 'F', 'T', 'V', 'G', 'W', 'P'],
    ['C', 'T', 'B', 'G', 'Q', 'H', 'S'],
    ['T', 'J', 'P', 'B', 'W'],
    ['G', 'D', 'C', 'Z', 'F', 'T', 'Q','M'],
    ['N', 'S', 'H', 'B', 'P', 'F']
] 

crates2 = copy.deepcopy(crates)

for line in input:
    words = line.split()
    
    amount = int(words[1])
    src = int(words[3]) - 1
    dst = int(words[5]) - 1

    for i in range(amount):
        crates[dst].append(crates[src].pop())
    
    crates2[dst].extend(crates2[src][-amount:])
    crates2[src] = crates2[src][:-amount]

ans = ""
ans2 = ""

for crate in crates:
    ans += crate[-1]

for crate in crates2:
    ans2 += crate[-1]

print(ans)
print(ans2)
