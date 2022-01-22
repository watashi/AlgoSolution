use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

const MAXN: usize = 23;
const MOD: i64 = 998244353;

fn gcd(a: i64, b: i64) -> (i64, i64, i64) {
    if b == 0 {
        (a, 1, 0)
    } else {
        let (g, x, y) = gcd(b, a % b);
        (g, y, x - a / b * y)
    }
}

fn main() {
    let n: usize = read_line().trim().parse().unwrap();
    let all: Vec<u32> = {
        let mut a: Vec<[i32; 26]> = Vec::with_capacity(1 << n);
        a.push([0; 26]);
        for m in 0..n {
            let mut c = [0; 26];
            for i in read_line().trim().as_bytes() {
                c[(i - b'a') as usize] += 1;
            }
            a.push(c);
            for i in 1..1 << m {
                let mut cc = a[i];
                for j in 0..26 {
                    cc[j] = cmp::min(cc[j], c[j]);
                }
                a.push(cc);
            }
        }
        a.iter()
            .map(|i| i.iter().fold(1, |m, &j| m * (j + 1) as i64 % MOD) as u32)
            .collect()
    };

    let inv: Vec<i64> = (0..=n)
        .map(|i| gcd(i as i64, MOD).1.rem_euclid(MOD))
        .collect();
    let mut any: Vec<[u32; MAXN + 1]> = Vec::with_capacity(1 << n);
    let mut ans = 0;
    any.push(Default::default());
    // println!("{:?}", inv);
    for i in 1usize..1 << n {
        let cnt: usize = i.count_ones() as usize;
        let mut sum: i64 = 0;
        let mut a = [0i64; MAXN + 1];
        let mut s = 0i64;
        for bit in 0..n {
            let j = i ^ (1 << bit);
            if i & j == j {
                sum += bit as i64 + 1;
                for k in 0..cnt {
                    a[k] += any[j][k] as i64;
                }
            }
        }
        for k in 1..cnt {
            a[k] = a[k] % MOD * inv[cnt as usize - k] % MOD;
        }
        let mut aa = [0; MAXN + 1];
        a[cnt] = all[i] as i64;
        for k in 1..=cnt {
            aa[k] = a[k] as u32;
            if k % 2 != 0 {
                s += a[k];
            } else {
                s -= a[k];
            }
        }
        // println!("{:6b} {:>5} {:>5} {:?}", i, all[i], s, a);
        any.push(aa);
        ans ^= s.rem_euclid(MOD) * cnt as i64 * sum;
    }
    println!("{}", ans);
}

// 140859535	Dec/27/2021 21:35UTC-8	watashi	1620G - Subsequences Galore	Rust 2021	Happy New Year!	4336 ms	886500 KB
