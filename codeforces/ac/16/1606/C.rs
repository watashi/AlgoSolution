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
        let mut m = read_vec::<i64>()[1] + 1;
        let a = read_vec::<u32>();
        let mut n = 0;
        for i in 1..a.len() {
            let c = cmp::min(m, 10i64.pow(a[i] - a[i - 1]) - 1);
            m -= c;
            n += c * 10i64.pow(a[i - 1]);
        }
        n += m * 10i64.pow(*a.last().unwrap());
        println!("{}", n);
    }
}

// 141596359	Jan/03/2022 18:43UTC-8	watashi	1606C - Banknotes	Rust 2021	Happy New Year!	109 ms	0 KB
