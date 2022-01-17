use std::*;

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

    fn is_prime(&self, n: usize) -> bool {
        n > 1 && self.0[n] == n
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

fn main() {
    let pt = PrimeTable::new(1_000_001);
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let ne = read_vec::<usize>();
        let (n, e) = (ne[0], ne[1]);
        let a = read_vec::<usize>();
        let mut ans = 0;
        for i in 0..e {
            for j in (i..n).into_iter().step_by(e) {
                if !pt.is_prime(a[j]) {
                    continue;
                }
                let (mut l, mut r) = (1, 1);
                while j >= l * e && a[j - l * e] == 1 {
                    l += 1;
                }
                while j + r * e < n && a[j + r * e] == 1 {
                    r += 1;
                }
                ans += l as u64 * r as u64 - 1;
            }
        }
        println!("{}", ans);
    }
}

// 143073094	Jan/16/2022 22:44UTC-8	watashi	1609C - Complex Market Analysis	Rust 2021	Accepted	140 ms	14000 KB
