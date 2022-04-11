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
    const ANS: [&str; 2] = ["Alice", "Bob"];
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [_, mut x, y] = read_vec::<u64>()[..] {
            for i in read_vec::<u64>() {
                x ^= i;
            }
            x ^= y;
            println!("{}", ANS[(x & 1) as usize]);
        }
    }
}

// 150320034	Mar/20/2022 21:32UTC-7	watashi	1634B - Fortune Telling	Rust 2021	Accepted	92 ms	4100 KB
