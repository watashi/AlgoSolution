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
        let mut c = collections::HashMap::<i32, i32>::new();
        for i in read_vec::<i32>() {
            *c.entry(i.abs()).or_default() += 1;
        }
        c.get_mut(&0).map(|i| *i = 1);
        println!("{}", c.into_values().map(|i| i.min(2)).sum::<i32>());
    }
}

// 147140627	Feb/20/2022 21:34UTC-8	watashi	1616A - Integer Diversity	Rust 2021	Accepted	15 ms	400 KB
