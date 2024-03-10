# PART 1 & 2
from math import sqrt, floor, ceil, prod

with open("6.in") as file:
    times = list(map(int, filter(lambda x: x.isnumeric(), file.readline().replace("\n", "").split(" "))))
    distances = list(map(int, filter(lambda x: x.isnumeric(), file.readline().replace("\n", "").split(" "))))

    times.append(int("".join(map(str, times))))
    distances.append(int("".join(map(str, distances))))

    ways = [0 for _ in range(len(times))]

    # All x such that x * (x-t) > d 
    # Such values are in between the x-intercepts of the parabola
    for i in range(len(times)):
        right_x_intercept = ceil( (times[i] + sqrt(times[i] ** 2 - 4 * distances[i]) ) / 2 - 1)
        left_x_intercept = floor( (-1 * times[i] + sqrt(times[i] ** 2 - 4 * distances[i])) / (-2) + 1)

        ways[i] = (right_x_intercept - left_x_intercept + 1)

    print(prod(ways[:-1]))
    print(ways[-1])

