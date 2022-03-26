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
        let x = *a.last().unwrap();
        let mut n = 1;
        let mut ans = 0;
        while n < a.len() {
            if a[a.len() - n - 1] == x {
                n += 1;
            } else {
                n *= 2;
                ans += 1;
            }
        }
        println!("{}", ans);
    }
}

// 147834387	Feb/27/2022 00:27UTC-7	watashi	1631B - Fun with Even Subarrays	Rust 2021	Accepted	124 ms	4100 KB
