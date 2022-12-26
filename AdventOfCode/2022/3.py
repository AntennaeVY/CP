rucksacks = open("3.in").read().strip().split()
ans = 0

for rucksack in rucksacks:
    mid = len(rucksack) // 2

    compartment_1 = set(rucksack[:mid])
    compartment_2 = set(rucksack[mid:])
    
    intersection = compartment_1 & compartment_2

    for item in intersection:
        if (item.isupper()):
            ans += ord(item) - 38
        else:
            ans += ord(item) - 96

print(ans)
ans = 0

for i in range(0, len(rucksacks), 3):
    group = [set(x) for x in rucksacks[i:i+3]]

    intersection = set.intersection(*group);

    for item in intersection:
        if (item.isupper()):
            ans += ord(item) - 38
        else:
            ans += ord(item) - 96

print(ans)

