elves = [sum(map(int, i.split())) for i in open("1.in").read().split("\n\n")]

print(max(elves))
print(sum(sorted(elves)[-3::]))
