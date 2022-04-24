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
        let ans = read_vec::<u32>().iter().fold(0, |i, &j| i | j);
        println!("{}", ans);
    }
}

// 150671693	Mar/23/2022 23:05UTC-7	watashi	1635A - Min Or Sum	Rust 2021	Accepted	30 ms	200 KB
