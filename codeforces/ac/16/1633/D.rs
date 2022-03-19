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
    const MAXN: usize = 1010;
    let mut cost = vec![usize::MAX; MAXN];
    cost[0] = 0;
    cost[1] = 0;
    for i in 1..MAXN {
        for j in 1..=i {
            let k = i + i / j;
            if k < MAXN {
                cost[k] = cost[k].min(cost[i] + 1);
            }
        }
    }
    let cost = cost;

    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let k = read_vec::<usize>()[1];
        let b = read_vec::<usize>();
        let c = read_vec::<u32>();
        let s = b.iter().map(|&i| cost[i]).sum::<usize>();
        let mut dp = vec![0; k.min(s) + 1];
        let mut s = 0;
        for (i, j) in b.into_iter().zip(c) {
            s += cost[i];
            for k in (cost[i]..=k.min(s)).rev() {
                dp[k] = dp[k].max(dp[k - cost[i]] + j);
            }
        }
        println!("{}", dp.iter().max().unwrap());
    }
}

// 150179206	Mar/19/2022 15:24UTC-7	watashi	1633D - Make Them Equal	Rust 2021	Accepted	31 ms	100 KB
