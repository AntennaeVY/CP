import requests
import json

def send_request(URL, params):
	r = requests.get(url=URL, params = params);
	
	return list(r.json());

url = input()
port = input()
a = int(input())
b = int(input())

numbers = send_request(url+":"+port, {"a": a, "b": b})

ans = 0
for number in numbers:
	ans += number
	
print(ans)