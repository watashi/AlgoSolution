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
    let c2 = |n: i64| n * (n + 1) / 2;
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [k, x] = read_vec::<i64>()[..] {
            let r = 2 * k - 1;
            let (mut lo, mut hi) = (1, r);
            while lo < hi {
                let mi = (lo + hi) / 2;
                if if mi <= k { c2(mi) } else { k * k - c2(r - mi) } < x {
                    lo = mi + 1;
                } else {
                    hi = mi;
                }
            }
            println!("{}", hi);
        }
    }
}

// 141470499	Jan/03/2022 01:32UTC-8	watashi	1612C - Chat Ban	Rust 2021	Happy New Year!	124 ms	0 KB
