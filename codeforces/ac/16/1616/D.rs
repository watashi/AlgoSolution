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
        let x: i32 = read_line().trim().parse().unwrap();
        let mut dp = [0, 1, 0];
        for i in 1..a.len() {
            let pre = dp;
            dp[0] = *pre.iter().max().unwrap();
            dp[1] = pre[0] + 1;
            dp[2] = 0;
            if a[i] + a[i - 1] >= 2 * x {
                dp[2] = pre[1] + 1;
                if i >= 2 && a[i] + a[i - 1] + a[i - 2] >= 3 * x {
                    dp[2] = dp[2].max(pre[2] + 1);
                }
            }
        }
        println!("{}", dp.iter().max().unwrap());
    }
}

// 147128256	Feb/20/2022 18:05UTC-8	watashi	1616D - Keep the Average High	Rust 2021	Accepted	15 ms	1100 KB
