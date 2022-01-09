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
        if let [mut x, n] = read_vec::<i64>()[..] {
            for i in (n & !3) + 1..=n {
                if x % 2 == 0 {
                    x -= i;
                } else {
                    x += i;
                }
            }
            println!("{}", x);
        }
    }
}

// 141887253	Jan/07/2022 00:17UTC-8	watashi	1607B - Odd Grasshopper	Rust 2021	Happy New Year!	92 ms	0 KB
