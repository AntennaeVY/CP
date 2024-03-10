# PART 1 
with open("4.in") as file:
    sum1 = 0

    for line in file:
        lists = line.split(": ")[1].split(" | ")

        lists[0] = lists[0].lstrip().replace("  ", " ")
        lists[1] = lists[1].lstrip().replace("  ", " ")

        mine = list(map(int, lists[0].split(" ")))
        winning = set(map(int, lists[1].replace("\n", "").split(" ")))

        count = 0

        for card in mine:
            count += card in winning


        if count > 0:
            sum1 += 1 << count - 1

    print(sum1)

# PART 2
with open("4.in") as file:
    cards = [1 for _ in open('4.in')]
    results = [-1 for _ in cards]

    i = 0

    for line in file:
        for time in range(0, cards[i]): 
            if results[i] >= 0:
                for x in range(i+1, min(len(cards), i + results[i] + 1)):
                    cards[x] += cards[i] - 1 
                break

            lists = line.split(": ")[1].split(" | ")

            lists[0] = lists[0].lstrip().replace("  ", " ")
            lists[1] = lists[1].lstrip().replace("  ", " ")

            mine = list(map(int, lists[0].split(" ")))
            winning = set(map(int, lists[1].replace("\n", "").split(" ")))

            count = 0

            for card in mine:
                count += card in winning

            results[i] = count

            for x in range(i+1, min(len(cards), i + count + 1)):
                cards[x] += 1
        i += 1

    print(sum(cards))

