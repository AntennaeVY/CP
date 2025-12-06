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
    
    let mut ranges: Vec<(i64, i64)> = Vec::new();
    
    loop {
        let mut line = String::new();
        let cnt = reader.read_line(&mut line).unwrap();

        line = line.trim().to_string();

        if cnt <= 2 {
            break;
        }

        let parsed: Vec<(i64, i64)> = line
            .split(',')
            .map(|x| {
                let mut it = x.split('-');
                let start = it.next().unwrap().trim().parse::<i64>().unwrap();
                let end   = it.next().unwrap().trim().parse::<i64>().unwrap();
                (start, end)
            })
            .collect();

        ranges.extend(parsed);
    }

    ranges.sort();

    let mut merged_ranges: Vec<(i64, i64)> = Vec::new();

    let mut start = ranges[0];
    for (a, b) in &ranges {
        if *a >= start.0 && *a <= start.1 {
            start.1 = cmp::max(*b, start.1);
        } else {
            merged_ranges.push(start);
            start = (*a, *b);
        }
    }

    merged_ranges.push(start);

    let mut candidates: Vec<i64> = Vec::new();

    loop {
        let mut line = String::new();
        let cnt = reader.read_line(&mut line).unwrap();

        if cnt == 0 {
            break;
        }

        line = line.trim().to_string();
        candidates.push(line.parse::<i64>().unwrap()); 
    }

    let mut ans1 = 0;
    let mut ans2 = 0;

    let mut lookup: BTreeSet<i64> = BTreeSet::new();
    for (a, b) in &merged_ranges {
        for candidate in &candidates {
            if *candidate >= *a && *candidate <= *b {
                lookup.insert(*candidate);
            }
        }

        ans2 += *b - *a + 1;
    }

    ans1 += lookup.len();

    println!("PART 1: {}", ans1);
    println!("PART 2: {}", ans2);
}
