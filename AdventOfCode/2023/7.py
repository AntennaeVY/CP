# PART 1
from functools import cmp_to_key

def sort_by_rank(t1, t2):
    rank = {
      "A": 13,
      "K": 12,
      "Q": 11,
      "J": 10,
      "T": 9,
      "9": 8,
      "8": 7,
      "7": 6,
      "6": 5,
      "5": 4,
      "4": 3,
      "3": 2,
      "2": 1,
    }

    h = [t1[0], t2[0]]
    cnt = [{}, {}]

    for i in range(2):
        for c in h[i]:
            cnt[i][c] = cnt[i].get(c, 0) + 1

    s_h = [[], []]

    for i in range(2):
        s_h[i] = sorted([tuple(reversed(x)) for x in cnt[i].items()], reverse=True, key=lambda x: (x[0], rank[x[1]]))

    # START OF PART 2
    for i in range(2):
        j = cnt[i].get('J', 0)

        s_h[i] = [x for x in s_h[i] if x == (5, 'J') or x[1] != 'J']
        
        if (s_h[i][0][1] != 'J'):
            s_h[i][0] = (s_h[i][0][0] + j, s_h[i][0][1])
    # END OF  PART 2

    for i in range(min(len(s_h[0]), len(s_h[1]))): 
        if s_h[0][i][0] < s_h[1][i][0]:
                return -1
        elif s_h[0][i][0] > s_h[1][i][0]:
                return 1
    
    for i in range(5):
        if rank[h[0][i]] < rank[h[1][i]]:
            return -1
        elif rank[h[0][i]] > rank[h[1][i]]:
            return 1

    return 0
    


with open("7.in") as file:
    hands = []

    for line in file:
        hand, bid = line.replace("\n", "").split(" ")

        hands.append((hand, bid))

    hands.sort(key=cmp_to_key(sort_by_rank))

    ans = 0

    for i in range(len(hands)):
        ans += int(hands[i][1]) * (i+1)

    print(*hands, sep="\n")
    print(ans)
