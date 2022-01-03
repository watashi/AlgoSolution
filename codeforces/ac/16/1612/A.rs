use std::{cmp::*, *};

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
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
        if let [x, y] = read_vec::<i64>()[..] {
            let (a, b) = if x % 2 != y % 2 {
                (-1, -1)
            } else {
                let d = (x + y) / 2;
                let dx = min(x, d);
                (x - dx, y - d + dx)
            };
            println!("{} {}", a, b);
        }
    }
}

// 141472824	Jan/03/2022 02:03UTC-8	watashi	1612A - Distance	Rust 2021	Happy New Year!	61 ms	0 KB
