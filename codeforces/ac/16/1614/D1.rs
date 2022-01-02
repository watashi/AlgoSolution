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

struct PrimeTable(Vec<usize>);

impl PrimeTable {
    fn new(n: usize) -> Self {
        let mut p = vec![0; cmp::max(2, n)];
        p[1] = 1;
        for i in 2..n {
            if p[i] == 0 {
                p[i] = i;
                for j in (i.saturating_mul(i)..n).step_by(i) {
                    if p[j] == 0 {
                        p[j] = i;
                    }
                }
            }
        }
        PrimeTable(p)
    }

    fn prime_factors(&self, mut n: usize) -> Vec<(usize, u32)> {
        let p = &self.0;
        debug_assert!(0 < n && n < p.len());
        let mut d: Vec<(usize, u32)> = vec![];
        while n > 1 {
            if d.is_empty() || d.last().unwrap().0 != p[n] {
                d.push((p[n], 1));
            } else {
                d.last_mut().unwrap().1 += 1
            }
            n /= p[n];
        }
        d
    }

    fn factors(&self, n: usize) -> Vec<usize> {
        fn gen(mut i: slice::Iter<(usize, u32)>, mut x: usize, f: &mut Vec<usize>) {
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

fn main() {
    const MAXN: usize = 5_000_005;
    let p = PrimeTable::new(MAXN);

    let mut c = vec![0; MAXN];
    read_line();
    for i in read_vec::<usize>() {
        c[i] += 1;
    }
    for i in 2..MAXN {
        if c[i] > 0 {
            for j in p.factors(i) {
                if j < i {
                    c[j] += c[i];
                }
            }
        }
    }

    let mut s = vec![0; MAXN];
    s[1] = c[1];
    for i in 2..MAXN {
        if c[i] > 0 {
            for (j, _) in p.prime_factors(i) {
                let k = i / j;
                s[i] = cmp::max(s[i], s[k] + k as u64 * (j as u64 - 1) * c[i]);
            }
        }
    }
    println!("{}", s.iter().max().unwrap());
}

// 141343754	Jan/01/2022 10:50UTC-8	watashi	1614D1 - Divan and Kostomuksha (easy version)	Rust 2021	Happy New Year!	342 ms	119500 KB
