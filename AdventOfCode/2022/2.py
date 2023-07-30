rounds = [round.split() for round in open("2.in").read().strip().split('\n')]

ans = 0

for round in rounds:
    first, second = round

    ans += ord(second) - 87;
   
    if (ord(first) - 64 == ord(second) - 87):
        ans += 3
    
    if (first == 'A' and second == 'Y' or first == 'B' and second == 'Z' or first == 'C' and second == 'X'):
        ans += 6

print(ans)
ans = 0

for round in rounds:
    first, second = round

    if (second == 'Z'):
        if (first == 'A'):
            ans += 8
        elif (first == 'B'):
            ans += 9
        else:
            ans += 7
    elif (second == 'Y'):
        ans += 3 + (ord(first) - 64)
    else:
        if (first == 'A'):
            ans += 3
        elif (first == 'B'):
            ans += 1
        else:
            ans += 2

print(ans)
    
