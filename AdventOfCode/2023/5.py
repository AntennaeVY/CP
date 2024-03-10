# PART 1
def parse_mapping(m, f):
    while (line := f.readline()) != '\n':
        if not line[0].isdigit():
            continue

        dst, src, cnt = list(map(int, line.replace("\n", "").split(" ")))

        m.append([src, dst, cnt])

def search_value(v, m):
    for l in m:
        src, dst, cnt = l

        if v >= src and v <= src+cnt-1:
            return dst + v - src

    return v

with open("5.in") as file:
    seeds = list(map(int, file.readline().split(": ")[1].replace("\n", "").split(" ")))

    mappings = [[] for _ in range(7)]

    for mapping in mappings:
        line = file.readline()
        parse_mapping(mapping, file)

    line = file.readline()

    min_location = float('inf')

    for seed in seeds:
        location = seed

        for mapping in mappings:
            location = search_value(location, mapping)

        min_location = min(min_location, location)

    print(min_location)

# PART 2
with open("5.in") as file:
    seeds = list(map(int, file.readline().split(": ")[1].replace("\n", "").split(" ")))

    seeds = [seeds[i:i+2] for i in range(0, len(seeds), 2)]

    for seed in seeds:
        seed[1] += seed[0] - 1

    mappings = [[] for _ in range(7)]

    for mapping in mappings:
        line = file.readline()
        parse_mapping(mapping, file)

    line = file.readline()

    for i in range(0, 7):
        for seed in seeds:
            for mapping in mappings[i]:
                if (
                    seed[0] >= mapping[0] and seed[0] < mapping[0] + mapping[2] or 
                    seed[1] >= mapping[0] and seed[1] < mapping[0] + mapping[2]
                ):
                    old = seed.copy() 
                    seed[0], seed[1] = max(seed[0], mapping[0]), min(seed[1], mapping[0] + mapping[2] - 1)
                    
                    if old[0] < seed[0]:
                        seeds.append([old[0], seed[0] - 1])

                    if old[1] > seed[1]:
                        seeds.append([seed[1]+1, old[1]])


            for mapping in mappings[i]:
                if (
                    seed[0] >= mapping[0] and seed[0] < mapping[0] + mapping[2] or
                    seed[1] >= mapping[0] and seed[1] < mapping[0] + mapping[2]
                ):
                    seed[0], seed[1] = seed[0] + mapping[1] - mapping[0], seed[1] + mapping[1] - mapping[0]
                    break


    print(min([min(x) for x in seeds]))



