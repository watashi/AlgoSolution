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
        if let [n, k] = read_vec::<usize>()[..] {
            if k == 1 || n % 2 == 0 {
                println!("YES");
                for i in 0..n {
                    let s = i / 2 * 2 * k + i % 2 + 1;
                    println!(
                        "{}",
                        (0..k)
                            .map(|j| (s + j * 2).to_string())
                            .collect::<Vec<_>>()
                            .join(" ")
                    );
                }
            } else {
                println!("NO");
            }
        }
    }
}

// 150319645	Mar/20/2022 21:24UTC-7	watashi	1634C - OKEA	Rust 2021	Accepted	31 ms	0 KB
