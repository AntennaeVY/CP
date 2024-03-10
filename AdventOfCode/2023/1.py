# PART 1
sum1 = 0

with open("1.in") as input:
    for line in input:
        digits = []

        for char in line:
            if char.isdigit():
                digits.append(char)
        
        if len(digits) > 0:
            sum1 += int(digits[0] + digits[-1])

print(sum1)

# PART 2
sum2 = 0

numbers = {
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9",
}

with open("1.in") as input:
    for line in input:
        first, last = len(line), -1

        for i in range(len(line)):
            if line[i].isdigit():
                first = i
                break

        for i in range(len(line)-1, -1, -1):
            if line[i].isdigit():
                last = i
                break

        new_first, new_last = -1, -1

        for i in range(0, first):
            if new_first != -1:
                break

            for word, value in numbers.items():
                pos = i

                for j in range(0, len(word)):
                    if pos < len(line) and line[pos] == word[j]:
                        pos += 1 
                    else: 
                        break

                    if pos - i == len(word):
                        new_first = value
                        break
                    
        for i in range(last+1, len(line)):
            for word, value in numbers.items():
                pos = i

                for j in range(0, len(word)):
                    if pos < len(line) and line[pos] == word[j]:
                        pos += 1 
                    else: 
                        break

                    if pos - i == len(word):
                        new_last = value
                        break           

        val1, val2 = "0", "0"

        if first != len(line):
            val1 = line[first]

        if last != -1:
            val2 = line[last]

        if new_first != -1:
            val1 = new_first

        if new_last != -1:
            val2 = new_last 


        sum2 += int(val1 + val2)

print(sum2)
