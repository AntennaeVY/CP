s = input()
d = input()
m = input()
	
def to_bin(x):
	return "{0:b}".format(x)

S = int(s, base=2)
D = int(d, base=2)
M = int(m, base=2)

cnt = M
last = 0
ans = 0
while cnt > 0:
	cnt //= 2
	last = cnt

	if (ans % D == D-1):
		cnt += S
	
	if (ans == 1000000):
		print("Infinite money!")
		exit(0)
		
	ans += 1
	
if (cnt == 0):
	print(to_bin(ans))
	exit(0)

	