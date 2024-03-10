import os
import sys
import requests

from dotenv import load_dotenv

load_dotenv()

cookies = {"session": os.getenv("AOC23_COOKIE")}

day = int(sys.argv[1])
r = requests.get(f'https://adventofcode.com/2023/day/{day}/input', cookies=cookies)

print(r.text)
