input = open("6.in").read().strip()

    def solve(k):
        for i in range(len(input)):
            if len(set(input[i:i+k])) == k:
                return i+k

print(solve(4))
print(solve(14))
