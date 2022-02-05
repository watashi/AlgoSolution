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
    let (n, m, k) = {
        let x = read_vec::<usize>();
        (x[0], x[1] as i32, x[2])
    };
    let mut d = read_vec::<i32>();
    d.push(m);
    let a = read_vec::<i32>();

    let mut dp = vec![vec![]; n + 1];
    dp[n] = vec![0];
    for (i, (&di, ai)) in d.iter().zip(a).enumerate().rev() {
        let mut dpi = vec![i32::MAX; n + 1 - i];
        for (&dj, dpj) in d.iter().zip(&dp).skip(i + 1) {
            let diff = ai * (dj - di);
            for (x, &y) in dpi.iter_mut().skip(1).zip(dpj) {
                if y < i32::MAX {
                    *x = (*x).min(y + diff);
                }
            }
        }
        dp[i] = dpi;
    }
    println!("{}", dp[0][n - k..].iter().min().unwrap());
}

// 143932591	Jan/24/2022 21:36UTC-8	watashi	1625C - Road Optimization	Rust 2021	Accepted	46 ms	500 KB
