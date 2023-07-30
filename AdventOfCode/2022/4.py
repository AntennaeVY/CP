assignments = open("4.in").read().strip().split()

ans = 0
ans2 = 0

for assignment in assignments:
    task1, task2 = assignment.split(',')
    l1, r1 = task1.split('-')
    l2, r2 = task2.split('-')

    if int(l1) <= int(l2) and int(r1) >= int(r2) or int(l1) >= int(l2) and int(r1) <= int(r2):
        ans += 1
        ans2 += 1
    elif int(l1) >= int(l2) and int(l1) <= int(r2) or int(r1) >= int(l2) and int(r1) <= int(r2):
        ans2 += 1

print(ans)
print(ans2)
