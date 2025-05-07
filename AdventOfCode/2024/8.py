file = []
try:
    while line := input():
        if line[-1] == '\r': 
            file.append(list(line)[:-1])
        else:
            file.append(list(line))
except:
    pass

n = len(file)
m = len(file[0])

mp = {}

for i in range(n):
    for j in range(m):
        ch = file[i][j]

        if ch == '.':
            continue

        if ch not in mp.keys():
            mp[ch] = []

        # j is x-axis and i is y-axis
        mp[ch].append((j, i))

# Part 1
st = set()

for ch, arr in mp.items():
    for i in range(len(arr)):
        for j in range(len(arr)):
            if i == j:
                continue

            x1, y1 = arr[i]
            x2, y2 = arr[j]

            dx = x1 - x2
            dy = y1 - y2

            X = abs(dx)
            Y = abs(dy)

            if dx > 0:
                if dy > 0:
                    # 2
                    #  .
                    #   1
                    if x2 - X >= 0 and y2 - Y >= 0:
                        st.add((x2 - X, y2 - Y))

                elif dy < 0:
                    #   1
                    #  .
                    # 2
                    if x2 - X >= 0 and y2 + Y < n:
                        st.add((x2 - X, y2 + Y))
 
                else:
                    # 
                    # 2 . 1
                    #
                    if x2 - X >= 0:
                        st.add((x2 - X, 0))
 
            elif dx < 0:
                if dy > 0:
                    #   2
                    #  .
                    # 1
                    if x2 + X < m and y2 - Y >= 0: 
                        st.add((x2 + X, y2 - Y))
                        
 
                elif dy < 0:
                    # 1
                    #  .
                    #   2
                    if x2 + X < m and y2 + Y < n:
                        st.add((x2 + X, y2 + Y))
 
                else:
                    #
                    # 1 . 2
                    #
                    if x2 + X < m:
                        st.add((x2 + X, 0))
                        
                    
            else:
                if dy > 0:
                    # 2
                    # .
                    # 1
                    if y2 - Y >= 0:
                        st.add((0, y2 - Y))
 
                elif dy < 0:
                    # 1
                    # .
                    # 2
                    if y2 + Y < n:
                        st.add((0, y2 + Y))
print(len(st))


# Part 2
st = set()

for ch, arr in mp.items():
    for i in range(len(arr)):
        for j in range(len(arr)):
            if i == j:
                continue

            x1, y1 = arr[i]
            x2, y2 = arr[j]

            dx = x1 - x2
            dy = y1 - y2

            X = abs(dx)
            Y = abs(dy)

            k = 0

            if dx > 0:
                if dy > 0:
                    # 2
                    #  .
                    #   1
                    while x2 - k*X >= 0 and y2 - k*Y >= 0:
                        st.add((x2 - k*X, y2 - k*Y))
                        k += 1 

                elif dy < 0:
                    #   1
                    #  .
                    # 2
                    while x2 - k*X >= 0 and y2 + k*Y < n:
                        st.add((x2 - k*X, y2 + k*Y))
                        k += 1
 
                else:
                    # 
                    # 2 . 1
                    #
                    while x2 - k*X >= 0:
                        st.add((x2 - k*X, 0))
                        k += 1
 
            elif dx < 0:
                if dy > 0:
                    #   2
                    #  .
                    # 1
                    while x2 + k*X < m and y2 - k*Y >= 0: 
                        st.add((x2 + k*X, y2 - k*Y))
                        k += 1
                        
 
                elif dy < 0:
                    # 1
                    #  .
                    #   2
                    while x2 + k*X < m and y2 + k*Y < n:
                        st.add((x2 + k*X, y2 + k*Y))
                        k += 1
 
                else:
                    #
                    # 1 . 2
                    #
                    while x2 + k*X < m:
                        st.add((x2 + k*X, 0))
                        k += 1
                        
                    
            else:
                if dy > 0:
                    # 2
                    # .
                    # 1
                    while y2 - k*Y >= 0:
                        st.add((0, y2 - k*Y))
                        k += 1
 
                elif dy < 0:
                    # 1
                    # .
                    # 2
                    while y2 + k*Y < n:
                        st.add((0, y2 + k*Y))
                        k += 1
print(len(st))

