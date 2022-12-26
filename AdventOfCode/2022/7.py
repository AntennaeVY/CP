input = open("7.in").read().strip().split('\n')[1:]

directory_size = {}
directory_contains = {}
dir_stack = ['/']

for line in input:
    words = line.split()

    current_dir = "".join(dir_stack)
    command = " ".join(words[:-1])

    directory_size[current_dir] = directory_size.get(current_dir, 0)
    directory_contains[current_dir] = directory_contains.get(current_dir, [])

    if line == "$ ls":
        continue

    if command == "$ cd":
        if words[-1] == "..":
            dir_stack.pop()
        else:
            dir_stack.append(words[-1] + "/")

        continue

    if words[0] == "dir":
        directory_contains[current_dir].append(words[1])
    else:
        directory_size[current_dir] += int(words[0])

sum = 0
space_to_be_freed = 70_000_000

for dir in reversed(directory_size.keys()):
    for contained_dir in directory_contains[dir]:
        directory_size[dir] += directory_size[f'{dir}{contained_dir}/']

for dir in directory_size.keys():
    if directory_size[dir] <= 100_000:
        sum += directory_size[dir]

    space_available_if_deleted = 70_000_000 - directory_size[
        '/'] + directory_size[dir]

    if space_available_if_deleted >= 30_000_000:
        space_to_be_freed = min(space_to_be_freed, directory_size[dir])

print(sum)
print(space_to_be_freed)
