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

    let mut matrix: Vec<Vec<u8>> = Vec::new();

    let mut ans_1 = 0;
    let mut ans_2 = 0;

    loop {
        let mut line = String::new();

        if reader.read_line(&mut line).unwrap() == 0 {
            break;
        }

        line = line.trim().to_string();
        
        matrix.push(line.into_bytes());
   }

    let d: Vec<(i32, i32)> = vec![
        (-1, 0),
        (-1, 1),
        (0, 1),
        (1,1),
        (1, 0),
        (1, -1),
        (0, -1),
        (-1, -1)
    ];

    for i in 0..matrix.len() {
        for j in 0..matrix[i].len() {

            if matrix[i][j] as char == '.' {
                continue;
            }

            let mut cnt = 0;

            for (dx, dy) in &d {
                if i as i32 + *dx < 0 || i as i32 + *dx >= matrix.len() as i32 {
                    continue;
                }

                if j as i32 + *dy < 0 || j as i32 + *dy >= matrix[i].len() as i32 {
                    continue;
                }

    
               if matrix[(i as i32 + *dx) as usize][(j as i32 + *dy) as usize] as char == '@' {
                    cnt += 1; 
                } 
            }

            if cnt < 4 {
                ans_1 += 1;
            }
        }
    }

    let mut marked: Vec<Vec<bool>> = vec![vec![false; matrix.len()]; matrix[0].len()]; 

    loop {
        let mut removed = 0;

        for i in 0..matrix.len() {
            for j in 0..matrix[i].len() {
                if matrix[i][j] as char == '.' {
                    continue;
                }
                if marked[i][j] {
                    continue;
                }

                let mut cnt = 0;

                for (dx, dy) in &d {
                    if i as i32 + *dx < 0 || i as i32 + *dx >= matrix.len() as i32 {
                        continue;
                    }

                    if j as i32 + *dy < 0 || j as i32 + *dy >= matrix[i].len() as i32 {
                        continue;
                    }

                    if marked[(i as i32 + *dx) as usize][(j as i32 + *dy) as usize] {
                        continue;
                    }
        
                    if matrix[(i as i32 + *dx) as usize][(j as i32 + *dy) as usize] as char == '@' {
                       cnt += 1; 
                    
                   } 
                }

                if cnt < 4 {
                    marked[i][j] = true;
                    removed += 1;
                    
                    ans_2 += 1;
                }
            }
        }

        if removed == 0 {
            break;
        }
    }

    println!("PART 1: {}", ans_1);
    println!("PART 2: {}", ans_2);
}
