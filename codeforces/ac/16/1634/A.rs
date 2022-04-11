use std::{io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let z = read_line().split_ascii_whitespace().skip(1).next().unwrap() == "0";
        let s = read_line();
        if z || s.trim().chars().rev().zip(s.chars()).all(|(i, j)| i == j) {
            println!("1");
        } else {
            println!("2");
        }
    }
}

// 150320221	Mar/20/2022 21:36UTC-7	watashi	1634A - Reverse and Concatenate	Rust 2021	Accepted	15 ms	0 KB
