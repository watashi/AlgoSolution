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
        if let [_, mut s] = read_vec::<i64>()[..] {
            let a = read_vec::<i64>();
            let mut ans = (0, 0);
            let mut k = 0;
            for (i, &e) in a.iter().enumerate() {
                s += e;
                while s < 0 {
                    s -= a[k];
                    k += 1;
                }
                ans = cmp::max(ans, (i + 1 - k, k));
            }
            if ans.0 > 0 {
                println!("{} {}", ans.1 + 1, ans.1 + ans.0);
            } else {
                println!("-1");
            }
        }
    }
}

// 141358190	Jan/01/2022 18:21UTC-8	watashi	1611F - ATM and Students	Rust 2021	Happy New Year!	93 ms	7700 KB
