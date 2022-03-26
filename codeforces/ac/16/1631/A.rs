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
        let b = read_vec::<i32>();
        let x = a.iter().zip(&b).map(|(i, j)| i.min(j)).max().unwrap();
        let y = a.iter().chain(&b).max().unwrap();
        println!("{}", x * y);
    }
}

// 147833349	Feb/27/2022 00:15UTC-7	watashi	1631A - Min Max Swap	Rust 2021	Accepted	15 ms	0 KB
