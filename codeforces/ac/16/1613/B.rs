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
    let mut ans = vec![];
    for _ in 0..re {
        read_line();
        let mut a = read_vec::<i32>();
        a.sort_unstable();
        for &i in a.iter().rev().take(a.len() / 2) {
            ans.push(format!("{} {}", i, a[0]));
        }
    }
    println!("{}", ans[..].join("\n"));
}

// 143569951	Jan/21/2022 19:48UTC-8	watashi	1613B - Absent Remainder	Rust 2021	Accepted	31 ms	7600 KB
