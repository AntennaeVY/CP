use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::collections::{BTreeSet, HashMap};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("Usage: ./day input_file");

        return ();
    }

    let f = File::open(&args[1]).expect("Input not found");
    let mut reader = BufReader::new(f);

    let mut matrix: Vec<Vec<char>> = Vec::new();

    let mut ans_1 = 0;
    let mut ans_2 = 0;

    loop {
        let mut line = String::new();

        if reader.read_line(&mut line).unwrap() == 0 {
            break;
        }

        let row: Vec<char> = line.trim().to_string().chars().collect();

        matrix.push(row);
   }

    let mut positions: BTreeSet<usize> = BTreeSet::new();
    let mut positions2: HashMap<usize, i64> = HashMap::new();

    positions.insert(matrix[0].iter().position(|c| *c == 'S').expect("S not found"));
    positions2.insert(matrix[0].iter().position(|c| *c == 'S').expect("S not found"), 1);

    for i in 1..matrix.len() {
        let mut updates: BTreeSet<usize> = BTreeSet::new();
        let mut updates2: HashMap<usize, i64> = HashMap::new();

        for j in 0..matrix[i].len() {
            if matrix[i][j] == '^' {
                if positions.contains(&j) {
                    positions.remove(&j);

                    updates.insert(j+1);
                    updates.insert(j-1);

                    updates2.entry(j+1).or_insert(0);
                    updates2.entry(j+1).and_modify(|x| *x += positions2.get(&j).copied().unwrap_or(0));

                    updates2.entry(j-1).or_insert(0);
                    updates2.entry(j-1).and_modify(|x| *x += positions2.get(&j).copied().unwrap_or(0));

                    updates2.entry(j).or_insert(0);
                    updates2.entry(j).and_modify(|x| *x = 0);

                    ans_1 += 1;
                }    
            } 
        }

        positions.append(&mut updates);

        for k in updates2.keys() {
            positions2.entry(*k).or_insert(0);
            positions2.entry(*k).and_modify(|x| {
                if matrix[i][*k] == '^' {
                    *x = updates2.get(&k).copied().unwrap();
                } else {
                    *x += updates2.get(&k).copied().unwrap();
                }
            });
        }
    }

    for (_, v) in positions2 {
        ans_2 += v;
    }

    println!("PART 1: {}", ans_1);
    println!("PART 2: {}", ans_2);
}
