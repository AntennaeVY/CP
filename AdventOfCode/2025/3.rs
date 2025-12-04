use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::cmp;

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

    loop {
        let mut line = String::new();

        if reader.read_line(&mut line).unwrap() == 0 {
            break;
        }

        line = line.trim().to_string();

        let mut d_max = -1;
        let mut l_max = 0;
        
        let mut states: Vec<i64> = vec![-1; 13];

        for d in line.chars().rev() {
            let x = d.to_digit(10).unwrap() as i64;
            let mut cnt;

            if d_max != -1 {
                cnt = x * 10 + d_max;
            } else {
                cnt = x;
            }

            l_max = cmp::max(l_max, cnt);
            d_max = cmp::max(d_max, x);


            for i in (1..=12).rev() {
               if states[i-1] != -1 {
                    states[i] = cmp::max(states[i], x * 10_i64.pow((i-1) as u32) + states[i-1]);     
                } 
            }

            states[1] = cmp::max(states[1], x);
        }

        ans_1 += l_max;
        ans_2 += states[12];
    }

    println!("PART 1: {}", ans_1);
    println!("PART 2: {}", ans_2);
}
