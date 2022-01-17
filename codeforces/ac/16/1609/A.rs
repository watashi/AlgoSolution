use std::{io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let mut a = read_vec::<u64>();
        let mut b = 1;
        for i in a.iter_mut() {
            while *i % 2 == 0 {
                *i /= 2;
                b *= 2;
            }
        }
        let amax = a.iter().max().unwrap();
        println!("{}", amax * (b - 1) + a.iter().sum::<u64>());
    }
}

// 143076829	Jan/16/2022 23:08UTC-8	watashi	1609A - Divide and Multiply	Rust 2021	Accepted	109 ms	0 KB
