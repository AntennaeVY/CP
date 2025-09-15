n = int(input())
a = list(map(int, input().split(" ")));

mx = pow(2, 100)

while(len(a) > 1):
	merged = True
	mn = mx
	
	while(merged):
		merged = False
		b = [a[0]]
		nmn = b[0]
	
		for i in range(1, len(a)):
			if a[i] == a[i-1]:
				b.pop()
				b.append(2*a[i])
				a[i], a[i-1] = 0, 0
				merged = True
			else:
				b.append(a[i])
				
			nmn = min(nmn, b[-1])
			
		a = b
		mn = nmn
		
	if (len(a) == 1):
		break
		
	b = []
	
	for x in a:
		if x != mn:
			b.append(x)	
	a = b
		
print(a[0])
	
		
		
			 