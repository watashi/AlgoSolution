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
        let n = a.len();
        if a.iter().skip(1).zip(&a).all(|(i, j)| i >= j) {
            println!("0");
        } else if a[n - 1] >= 0 && a[n - 2] <= a[n - 1] {
            let ans = (2..n)
                .rev()
                .map(|i| format!("{} {} {}", i - 1, i, n))
                .collect::<Vec<_>>();
            println!("{}\n{}", ans.len(), ans.join("\n"));
        } else {
            println!("-1");
        }
    }
}

// 150671189	Mar/23/2022 22:56UTC-7	watashi	1635C - Differential Sorting	Rust 2021	Accepted	202 ms	19000 KB
