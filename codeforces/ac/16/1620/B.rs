use std::{cmp::max, *};

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
        let wh = read_vec::<i64>();
        let d: Vec<i64> = (0..4)
            .map(|_| {
                let x = read_vec::<i64>();
                *x.iter().skip(1).max().unwrap() - *x.iter().skip(1).min().unwrap()
            })
            .collect();
        println!("{}", max(max(d[2], d[3]) * wh[0], max(d[0], d[1]) * wh[1]));
    }
}

// 140844588	Dec/27/2021 14:11UTC-8	watashi	1620B - Triangles on a Rectangle	Rust 2021	Happy New Year!	109 ms	2700 KB
