use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("Usage: ./day input_file");

        return ();
    }

    let f = File::open(&args[1]).expect("Input not found");
    let mut reader = BufReader::new(f);

    let mut ans_1 = 0;
    let mut ans_2 = 0;

    let mut pos = 50;

    loop {
        let mut line = String::new();

        if reader.read_line(&mut line).unwrap() == 0 {
            break;
        }

        line.pop();
        let mut cnt = line[1..].parse::<i32>().unwrap();

        let prev = pos;
        let mut dir = 0;

        match line.chars().nth(0).unwrap() {
            'L' => {
                pos -= cnt;
                dir = -1
            }
            'R' => {
                pos += cnt;
                dir = 1
            }
            _ => (),
        }

        if (pos % 100 + 100) % 100 == 0 {
            ans_1 += 1;
        }

        let mut d = prev;

        if dir == 1 {
            d = 100 - prev;
        }

        if d <= cnt {
            if d != 0 {
                ans_2 += 1;
            }

            cnt -= d;
            ans_2 += cnt / 100;
            pos = (pos % 100 + 100) % 100;
        }
    }

    println!("PART 1: {}", ans_1);
    println!("PART 2: {}", ans_2);
}
