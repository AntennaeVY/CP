t = int(input())

for _ in range(t):
	h, m = map(int, input().split(":"))
	
	s = "PM" if h >= 12 else "AM"
	
	new_h = h
	
	if h == 0:
		new_h = 12
	elif h > 12:
		new_h = h - 12
		
	print(str(new_h).zfill(2) + ":" + str(m).zfill(2) + " " + s)