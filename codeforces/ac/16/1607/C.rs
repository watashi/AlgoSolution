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
        let mut a = read_vec::<i32>();
        a.sort_unstable();
        let ans = a
            .iter()
            .skip(1)
            .zip(&a)
            .fold(a[0], |k, (&i, &j)| cmp::max(k, i - j));
        println!("{}", ans);
    }
}

// 141886147	Jan/07/2022 00:03UTC-8	watashi	1607C - Minimum Extraction	Rust 2021	Happy New Year!	124 ms	6900 KB
