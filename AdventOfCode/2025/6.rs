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

    let mut matrix: Vec<Vec<String>> = Vec::new();
    let mut matrix2: Vec<Vec<char>> = Vec::new();

    let mut ans_1 = 0;
    let mut ans_2 = 0;

    loop {
        let mut line = String::new();

        if reader.read_line(&mut line).unwrap() == 0 {
            break;
        }

        let row: Vec<String> = line.trim().to_string().split_whitespace().map(|s| s.to_string()).collect();
        let row2: Vec<char> = line.chars().collect();

        matrix.push(row);
        matrix2.push(row2);
   }

    for j in 0..matrix[0].len() {
        let op = &matrix[matrix.len()-1][j];
        let mut result = matrix[matrix.len()-2][j].parse::<i64>().unwrap();

        for i in (0..matrix.len()-2).rev() {
            match op.as_str() {
                "*" => result *= matrix[i][j].parse::<i64>().unwrap(),
                "+" => result += matrix[i][j].parse::<i64>().unwrap(),
                _ => ()
            }
        }
        
        ans_1 += result;
    }

    let n = matrix2.len();
    let m = matrix2[0].len();

    let mut op = ' ';
    let mut result = 0;

    for x in 0..m {
        if matrix2[n-1][x] == '\n' || matrix2[n-1][x] == '\r' {
            continue
        }

        if matrix2[n-1][x+1] == '*' || matrix2[n-1][x+1] == '+' { 
            continue;
        }

        if matrix2[n-1][x] == '+' {
            ans_2 += result;

            op = matrix2[n-1][x];
            result = 0;
        }

        if  matrix2[n-1][x] == '*' {
            ans_2 += result;

            op = matrix2[n-1][x];
            result = 1;
        }

        let mut num = String::new(); 

        for i in 0..n-1 {
            if matrix2[i][x].is_digit(10) {
                num.push(matrix2[i][x]);
            }
        }

        match op {
            '+' => result += num.parse::<i64>().unwrap(),
            '*' => result *= num.parse::<i64>().unwrap(),
            _ => ()
        }
    } 

    ans_2 += result;

    println!("PART 1: {}", ans_1);
    println!("PART 2: {}", ans_2);
}
