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
    const LCM: u64 = 720720;  // lcm(1..16)
    const MOD: u64 = 998244353;
    let [n, mut a, x, y, k, m]: [u64; 6] = read_vec::<u64>().try_into().unwrap();
    let mut dp = (0..LCM).collect::<Vec<_>>();
    let mut nk1 = 1; // n^(k-1)
    for k in (1..k as usize).rev() {
        nk1 = nk1 * n % MOD;
        for i in (0..LCM as usize).rev() {
            dp[i] = ((n - 1) * dp[i] + i as u64 * nk1 + dp[i - i % k]) % MOD;
        }
    }
    let mut ans = 0;
    for _ in 0..n {
        ans += a / LCM * LCM * nk1 % MOD * k;
        ans += dp[(a % LCM) as usize];
        a = (a * x + y) % m;
    }
    println!("{}", ans % MOD);
}

// 143952640	Jan/25/2022 00:59UTC-8	watashi	1626F - A Random Code Problem	Rust 2021	Accepted	234 ms	5600 KB
