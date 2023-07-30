t = int(input())

for _ in range(t):
	n, c = map(int, input().split(" "))
	
	s, s2 = 0, 0
	
	for p in map(int, input().split(" ")):
		s += p
		s2 += p*p
		
	l, r = 0, int(1e18)
	
	while l+1 < r:
		w = l + (r-l)//2;
			
		sum = 4*n*w*w + 4*s*w + s2;
		
		if (sum >= c):
			r = w;
		else:
			l = w;
		
	print(r)