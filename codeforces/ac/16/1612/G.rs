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

const MOD: i64 = 1_000_000_007;
const MAXN: usize = 1_000_001;

fn sum(a: impl IntoIterator<Item = i64>) -> i64 {
    a.into_iter().sum::<i64>() % MOD
}

fn product(a: impl IntoIterator<Item = i64>) -> i64 {
    a.into_iter().fold(1, |b, i| b * i % MOD)
}

fn main() {
    let mut f: Vec<i64> = vec![1, 1];
    let mut g = 1;
    for i in 2..MAXN {
        g = g * i as i64 % MOD;
        f.push(g);
    }

    read_line();
    let mut c = vec![0; MAXN];
    let mut s = 0;
    for i in read_vec::<i64>() {
        c[i as usize] += 1;
        s += i;
    }

    let (mut x, mut y) = (0, 1);
    for i in (2..MAXN).rev() {
        let n = c[i];
        c[i - 2] += n;
        s -= 2 * n;
        x = sum([x, product([s + n, n, i as i64 - 1])]);
        y = product([y, f[n as usize], f[n as usize]]);
    }
    y = product([y, f[c[1] as usize]]);
    println!("{} {}", x, y);
}

// 141453140	Jan/02/2022 21:40UTC-8	watashi	1612G - Max Sum Array	Rust 2021	Happy New Year!	62 ms	30200 KB
