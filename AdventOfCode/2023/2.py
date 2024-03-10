# PART 1

with open("2.in") as file:
    sum1 = 0

    for line in file:
        splitted = line.split(" ")
        game_id = int(splitted[1].replace(":", ""))
        rounds = " ".join(splitted[2:]).split(";")
    
        ok = True

        for round in rounds:
            colors = {
                "red": 0,
                "green": 0,
                "blue": 0
            }

            balls = round.split(", ")

            for ball in balls:
                ball = ball.strip().replace(";", "").replace("\n", "")

                count, color = ball.split(" ")

                colors[color] += int(count)

                ok &= colors["red"] <= 12 and colors["green"] <= 13 and colors["blue"] <= 14


        if ok:
            sum1 += game_id
    
    print(sum1)

# PART 2

with open("2.in") as file:
    sum2 = 0

    for line in file:
        splitted = line.split(" ")
        game_id = int(splitted[1].replace(":", ""))
        rounds = " ".join(splitted[2:]).split(";")
    
        min_colors = {
            "red": 0,
            "green": 0,
            "blue": 0,
        }

        for round in rounds:
            colors = {
                "red": 0,
                "green": 0,
                "blue": 0
            }

            balls = round.split(", ")

            for ball in balls:
                ball = ball.strip().replace(";", "").replace("\n", "")

                count, color = ball.split(" ")

                colors[color] += int(count)

            for color, count in colors.items():
                min_colors[color] = max(min_colors[color], count)

        sum2 += min_colors["red"] * min_colors["green"] * min_colors["blue"]

    print(sum2)
