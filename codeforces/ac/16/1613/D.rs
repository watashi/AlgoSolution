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
    const MOD: i64 = 998244353;
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let a = read_vec::<usize>();
        let n = *a.iter().max().unwrap();
        let mut dp0 = vec![0; n + 2];
        let mut dp1 = vec![0; n + 2];
        dp0[0] = 1;
        for i in a {
            dp0[i + 1] = (dp0[i + 1] * 2 + dp0[i]) % MOD;
            dp1[i + 1] = dp1[i + 1] * 2 % MOD;
            if i > 0 {
                dp1[i - 1] = (dp1[i - 1] * 2 + dp0[i - 1]) % MOD;
            }
        }
        println!("{}", dp0.into_iter().skip(1).chain(dp1).sum::<i64>() % MOD);
    }
}

// 143568028	Jan/21/2022 19:10UTC-8	watashi	1613D - MEX Sequences	Rust 2021	Accepted	826 ms	13900 KB
