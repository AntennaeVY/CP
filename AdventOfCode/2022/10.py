input = open("10.in").read().strip().split("\n")

ans = 0
target = 20
cycle = 1
hold = 0
x = 1

crt = ""

for instruction in input:
    op, *amt = instruction.split(" ")

    amt = amt[0] if amt else 0

    if op == 'noop':
        hold = 1
    else:
        hold = 2

    for i in range(hold):
        print(x, cycle)

        if x <= (cycle%40) <= x+2:
            crt += "#"
        else:
            crt += "."

        if cycle == target and target < 240:
            ans += target*x
            target += 40

        cycle += 1

    if op == 'addx':
        x += int(amt)

print(ans)

[print(crt[i:i+40]) for i in range(0, len(crt), 40)]
