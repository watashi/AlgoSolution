use std::{cmp::*, *};

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec() -> Vec<usize> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [a, b] = read_vec()[..] {
            println!("{}", min(min(a, b), (a + b) / 4));
        }
    }
}

// 141382647	Jan/02/2022 01:25UTC-8	watashi	1611B - Team Composition: Programmers and Mathematicians	Rust 2021	Happy New Year!	109 ms	0 KB
