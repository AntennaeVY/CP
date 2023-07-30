class Monkey:
    def __init__(self, items, operation, test, test_true_monkey, test_false_monkey):
        self.items = items
        self.operation = operation
        self.test = test
        self.test_false_monkey = test_false_monkey
        self.test_true_monkey = test_true_monkey

big_mod = 2*3*5*7*11*13*17*19

def solve(monkeys, rounds, divide_worry=True):
    monkey_activeness = [0]*(len(monkeys))
   
    for _ in range(rounds):
        for i, monkey in enumerate(monkeys):
            monkey_activeness[i] += len(monkeys[i].items)

            for item in monkey.items:
                worry_level = monkey.operation(item)

                if divide_worry:
                    worry_level //= 3
                else:
                    worry_level %= big_mod

                new_monkey = 0

                if (monkey.test(worry_level)):
                    new_monkey = monkey.test_true_monkey
                else:
                    new_monkey = monkey.test_false_monkey

                monkeys[new_monkey].items.append(worry_level)

            monkey.items = []

    monkey_activeness.sort(reverse=True)

    return monkey_activeness[0] * monkey_activeness[1]



monkeys = [
    Monkey([85, 79, 63, 72], lambda old: old * 17, lambda old: old % 2 == 0, 2, 6),
    Monkey([53, 94, 65, 81, 93, 73, 57, 92], lambda old: old * old, lambda old: old % 7 == 0, 0, 2),
    Monkey([62, 63], lambda old: old + 7, lambda old: old % 13 == 0, 7, 6),
    Monkey([57, 92, 56], lambda old: old + 4, lambda old: old % 5 == 0, 4, 5),
    Monkey([67], lambda old: old + 5, lambda old: old % 3 == 0, 1, 5),
    Monkey([85, 56, 66, 72, 57, 99], lambda old: old + 6, lambda old: old % 19 == 0, 1, 0),
    Monkey([86, 65, 98, 97, 69], lambda old: old * 13, lambda old: old % 11 == 0, 3, 7),
    Monkey([87, 68, 92, 66, 91, 50, 68], lambda old: old + 2, lambda old: old % 17 == 0, 4, 3)
]

test_monkeys = [
    Monkey([79, 98], lambda old: old * 19, lambda old: old % 23 == 0, 2, 3),
    Monkey([54, 65, 75, 74], lambda old: old + 6, lambda old: old % 19 == 0, 2, 0),
    Monkey([79, 60, 97], lambda old: old * old, lambda old: old % 13 == 0, 1, 3),
    Monkey([74], lambda old: old + 3, lambda old: old % 17 == 0, 0, 1)
]

print(solve(monkeys, 20))
print(solve(monkeys, 10000, divide_worry=False))
