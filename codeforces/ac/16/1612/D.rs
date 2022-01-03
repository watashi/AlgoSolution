use std::{collections::*, *};

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

fn check(a: i64, b: i64, c: i64) -> bool {
    if a < b {
        check(b, a, c)
    } else if c > a {
        false
    } else if b == 0 {
        c == a
    } else {
        let d = a % b;
        (c >= d && (c - d) % b == 0) || check(b, d, c)
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let t = read_vec::<i64>();
        println!("{}", if check(t[0], t[1], t[2]) { "YES" } else { "NO" });
    }
}

// 141469416	Jan/03/2022 01:18UTC-8	watashi	1612D - X-Magic Pair	Rust 2021	Happy New Year!	109 ms	0 KB
