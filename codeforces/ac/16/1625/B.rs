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
        let mut m = collections::HashMap::new();
        let a = read_vec::<i32>();
        let n = a.len() as i32;
        for (i, j) in (0..).zip(a) {
            m.entry(j).or_insert(vec![]).push(i);
        }
        let ans = m
            .into_values()
            .filter_map(|v| v.windows(2).map(|w| w[1] - w[0]).min())
            .min()
            .map_or(-1, |i| n - i);
        println!("{}", ans);
    }
}

// 143934516	Jan/24/2022 22:00UTC-8	watashi	1625B - Elementary Particles	Rust 2021	Accepted	109 ms	18000 KB
