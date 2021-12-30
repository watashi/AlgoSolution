use std::{io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn gcd(a: i64, b: i64) -> (i64, i64, i64) {
    if b != 0 {
        let (g, x, y) = gcd(b, a % b);
        (g, y, x - a / b * y)
    } else if a > 0 {
        (a, 1, 0)
    } else {
        (-a, -1, 0)
    }
}

fn lcm(a: i64, b: i64) -> i64 {
    a / gcd(a, b).0 * b
}

fn find_pos(m: i64, n: i64, s: i64, t: i64) -> Vec<i64> {
    let n = 2 * n - 2;
    let mut v = vec![];
    let mut z = 0;
    while z < m {
        v.push(z + t - 1);
        v.push(z + n - t + 1);
        z += n;
    }
    for i in &mut v {
        *i -= s - 1;
        if *i < 0 {
            *i += m;
        }
    }
    // println!("{:?}", v);
    v
}

fn main() {
    const M: i64 = 1000000007;
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [nx, ny, sx, sy, tx, ty, pct] = read_vec::<i64>()[..] {
            let m = 2 * lcm(nx - 1, ny - 1);
            let mut v = find_pos(m, nx, sx, tx);
            v.extend(find_pos(m, ny, sy, ty));
            v.sort_unstable();
            v.dedup();
            while v.last() == Some(&m) {
                v.pop();
            }
            let (mut q, mut e, mut d) = (1, 0, 1);
            for i in v {
                let p = q * pct % M;
                q = q * (100 - pct) % M;
                e = e * 100 % M;
                d = d * 100 % M;
                e = (e + i % M * p) % M;
                // eprintln!("{}: {} {} {}", i, q, e, d);
            }
            // eprintln!("{} / {}", e + m * q, d - q);
            e = (e + m % M * q) % M * gcd(d - q, M).1 % M;
            if e < 0 {
                e += M
            }
            println!("{}", e);
        }
    }
}

// 141151484	Dec/30/2021 03:08UTC-8	watashi	1623D - Robot Cleaner Revisit	Rust 2021	Happy New Year!	31 ms	3500 KB
