use std::*;

pub struct PrimeTable(Vec<u32>);

impl PrimeTable {
    pub fn new(n: u32) -> Self {
        let n = n as usize;
        let mut p = vec![0; cmp::max(2, n)];
        p[1] = 1;
        for i in 2..n {
            if p[i] == 0 {
                p[i] = i as u32;
                for j in (i.saturating_mul(i)..n).step_by(i) {
                    if p[j] == 0 {
                        p[j] = i as u32;
                    }
                }
            }
        }
        PrimeTable(p)
    }

    pub fn prime_factors(&self, mut n: u32) -> Vec<(u32, u32)> {
        let p = &self.0;
        debug_assert!(0 < n && n < p.len() as u32);
        let mut d: Vec<(u32, u32)> = vec![];
        while n > 1 {
            let q = p[n as usize];
            let mut r = 1;
            n /= q;
            while p[n as usize] == q {
                r += 1;
                n /= q;
            }
            d.push((q, r));
        }
        d
    }

    pub fn factors(&self, n: u32) -> Vec<u32> {
        fn gen(mut i: slice::Iter<(u32, u32)>, mut x: u32, f: &mut Vec<u32>) {
            match i.next() {
                Some(&(p, r)) => {
                    for _ in 0..r {
                        gen(i.clone(), x, f);
                        x *= p;
                    }
                    gen(i, x, f);
                }
                None => {
                    f.push(x);
                }
            }
        }
        let d = self.prime_factors(n);
        let mut f = vec![];
        gen(d.iter(), 1, &mut f);
        f
    }
}

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

fn gcd(a: u32, b: u32) -> u32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn main() {
    const MAXN: u32 = 1_000_001;
    let pt = PrimeTable::new(MAXN);
    let n: usize = read_line().trim().parse().unwrap();
    let mut g = vec![0; MAXN as usize];
    for i in read_vec::<u32>() {
        for j in pt.factors(i) {
            g[j as usize] = gcd(i, g[j as usize]);
        }
    }
    let ans = g
        .into_iter()
        .enumerate()
        .filter(|&(i, j)| i == j as usize)
        .count();
    println!("{}", ans - n - 1);
}

// 145601832	Feb/07/2022 19:57UTC-8	watashi	1627D - Not Adding	Rust 2021	Accepted	561 ms	27900 KB
