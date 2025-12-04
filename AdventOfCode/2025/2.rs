use std::io::{BufRead, BufReader};
use std::fs::File;
use std::collections::BTreeSet;
use std::env;
use std::cmp;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("Usage: ./day input.in");
        return ();
    }

    let file = File::open(&args[1]).unwrap();
    let mut reader = BufReader::new(file);

    let mut line = String::new();
    reader.read_line(&mut line);

    line.pop();

    let ranges: Vec<(i64, i64)> = line
        .split(',')
        .map(|x| {
            let mut it = x.split('-');
            let start = it.next().unwrap().trim().parse::<i64>().unwrap();
            let end = it.next().unwrap().trim().parse::<i64>().unwrap();

            (start, end)
        })
        .collect();

    let max = ranges
        .iter()
        .reduce(|acc, e| cmp::max(acc, e))
        .unwrap();

    let mut ans1 = 0;
    let mut ans2 = 0;

    let mut lookup: BTreeSet<i64> = BTreeSet::new();

    for i in 1..=1000000 {
        for j in 2..=10 {
            let s = i.to_string();

            if s.len() * j > 10 {
                break;
            }

            let candidate = s.repeat(j).parse::<i64>().unwrap();

            if lookup.contains(&candidate) {
                break;
            }

            for (a, b) in &ranges {
                if candidate >= *a && candidate <= *b {
                    if j == 2 {
                        ans1 += candidate;
                    }

                    ans2 += candidate;
                    lookup.insert(candidate);
                }
            }
        }
    }

    println!("PART 1: {}", ans1);
    println!("PART 2: {}", ans2);
}
