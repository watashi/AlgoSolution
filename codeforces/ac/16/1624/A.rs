use std::*;

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
        read_line();
        let a = read_vec::<i32>();
        println!("{}", a.iter().max().unwrap() - a.iter().min().unwrap());
    }
}

// 143811564	Jan/23/2022 10:09UTC-8	watashi	1624A - Plus One on the Subset	Rust 2021	Accepted	109 ms	200 KB
