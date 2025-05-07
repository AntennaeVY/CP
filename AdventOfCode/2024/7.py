file = []

try:
    while line := input():
        file.append(line)
except:
    pass

# Part 1

ans = 0

for line in file:
    result, nums = line.split(": ")

    result = int(result)
    nums = list(map(int, nums.split(' ')))
    n = len(nums)

    can = False
    assert(n > 1)

    for i in range(1 << (n-1)):
        count = nums[0]

        # 0 is + and 1 is *
        for j in range(1, n):
            if ((i >> (j-1)) & 1):
                count *= nums[j]
            else:
                count += nums[j]

        can |= (count == result)

        if can:
            break

    if can:
        ans += result


print(ans)
        
# Part 2
def ternary(n):
    d = n//3
    r = n%3
    if n == 0:
        return '0'
    elif d == 0:
        return str(r)
    else:
        return ternary(d) + str(r)

ans = 0

for line in file:
    result, nums = line.split(": ")

    result = int(result)
    nums = list(map(int, nums.split(' ')))
    n = len(nums)

    can = False
    assert(n > 1)

    for i in range(pow(3, n-1)):
        count = nums[0]
        t = ternary(i).zfill(n-1)

        # 0 is +, 1 is * and 2 is ||
        for j in range(1, n):
            if t[j-1] == '1':
                count *= nums[j]
            elif t[j-1] == '2':
                count += nums[j]
            else:
                count = int(str(count) + str(nums[j]))

        can |= (count == result)

        if can:
            break

    if can:
        ans += result

print(ans)
