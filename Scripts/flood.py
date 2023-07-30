from random import randint
from time import sleep
from requests import post

# for i in range(10, 0, -1):
#     print(f"Starting attack in: %d" % i)
#     sleep(1)


for i in range(0, 1000):   
    user = ""
    password = ""
    num_lines_user = sum(1 for line in open('users.txt'))
    num_lines_password = sum(1 for line in open("passwords.txt"))
    n_user = randint(0, num_lines_user)
    n_password = randint(0, num_lines_password)

    with open("users.txt") as file:
        for j, line in enumerate(file):
            if (j == n_user):
                user = line.rstrip() + "@gmail.com"
    
    with open("passwords.txt") as file:
        for j, line in enumerate(file):
            if (j == n_password): 
                password = line.rstrip()
    
    data = {}
    url = 'http://example.com'
    
    response = post(url, data = data)

    print(f"Sent attack %s:%s -> STATUS [%d %s]" % (user, password, response.status_code, response.reason))


