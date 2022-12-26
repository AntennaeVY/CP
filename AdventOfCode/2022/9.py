import copy

moves = open("9.in").read().strip().split("\n")

s = {tuple([0, 0])}
head = [0, 0]
tail = [0, 0]

for move in moves:
    direction, amount = move.split()

    for i in range(int(amount)):
        old_head = list(head)

        if direction == 'U':
            head[1] += 1
        elif direction == 'D':
            head[1] -= 1
        elif direction == 'L':
            head[0] -= 1
        else:
            head[0] += 1

        if abs(head[0] - tail[0]) > 1 or abs(head[1] - tail[1]) > 1:
            tail = old_head

        s.add(tuple(tail))

print(len(s))

knots = [[0, 0] for _ in range(10)]
s = {tuple([0, 0])}

for move in moves:
    direction, amount = move.split()

    for i in range(int(amount)):
        if direction == 'U':
            knots[0][1] += 1
        elif direction == 'D':
            knots[0][1] -= 1
        elif direction == 'L':
            knots[0][0] -= 1
        else:
            knots[0][0] += 1

        for i in range(1, 10):
            hx, hy = knots[i-1]
            tx, ty = knots[i]

            if abs(hx-tx) > 1 or abs(hy-ty) > 1:
                tx += 0 if hx==tx else (hx-tx)//abs(hx-tx)
                ty += 0 if hy==ty else (hy-ty)//abs(hy-ty)

            knots[i] = [tx, ty]

        s.add(tuple(knots[-1]))

print(len(s))
