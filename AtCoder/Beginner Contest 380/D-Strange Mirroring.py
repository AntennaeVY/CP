s = input()
q = int(input())
k = list(map(lambda x: int(x) - 1, input().split(" ")))

for ki in k: 
	j = ki
	cnt = 0
	
	while j >= len(s):
		l = -1
		r = 65
		
		while l + 1 < r:
			m = l + (r-l)//2
			
			if j < 2**m * len(s):
				r = m
			else:
				l = m
				
		cnt += 1
		j -= 2**(r-1) * len(s)
	
	i = ki % len(s)
	
	if cnt % 2:
		if s[i].lower() == s[i]:
			print(s[i].upper(), end=" ")
		elif s[i].upper() == s[i]:
			print(s[i].lower(), end=" ")
	else:
		print(s[i], end=" ")
	