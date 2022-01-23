use std::{collections::*, *};

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

fn pow_mod(mut a: i64, mut b: i64, m: i64) -> i64 {
    let mut c = 1;
    while b > 0 {
        if b & 1 != 0 {
            c = c * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    c
}

fn is_primitive_root(r: i64, n: i64) -> bool {
    let m = n - 1;
    (2..)
        .take_while(|&i| i * i <= m)
        .all(|i| m % i != 0 || (pow_mod(r, i, n) != 1 && pow_mod(r, m / i, n) != 1))
}

fn primitive_root(n: i64) -> i64 {
    (2..).find(|&i| is_primitive_root(i, n)).unwrap()
}

pub struct Modulo {
    r: i64,
    m: i64,
}

impl Modulo {
    pub fn new(m: i64) -> Self {
        let r = primitive_root(m);
        Self { r: r, m: m }
    }

    pub fn pow(&self, a: i64, b: i64) -> i64 {
        pow_mod(a, b, self.m)
    }

    pub fn inv(&self, a: i64) -> i64 {
        self.pow(a, self.m - 2)
    }

    fn ntt_impl(a: &[i64], step: usize, r: i64, m: i64) -> Vec<i64> {
        let n = a.len();
        if n == 1 {
            vec![a[0]]
        } else {
            let rr = r * r % m;
            let be = Self::ntt_impl(&a[0..n - step], step * 2, rr, m);
            let bo = Self::ntt_impl(&a[step..n], step * 2, rr, m);
            let mut w = 1;
            be.iter()
                .chain(&be)
                .zip(bo.iter().chain(&bo))
                .map(|(e, o)| {
                    let b = (e + w * o) % m;
                    w = w * r % m;
                    b
                })
                .collect()
        }
    }

    pub fn ntt(&self, mut a: Vec<i64>) -> Vec<i64> {
        let mut n = 1;
        while n < a.len() {
            n <<= 1;
        }
        a.resize(n, 0);
        debug_assert!((self.m - 1) % n as i64 == 0);

        let step = (self.m - 1) / n as i64;
        let r1 = self.pow(self.r, step);
        Self::ntt_impl(&a, 1, r1, self.m)
    }

    pub fn intt(&self, a: Vec<i64>) -> Vec<i64> {
        let mut b = Self {
            r: self.inv(self.r),
            m: self.m,
        }
        .ntt(a);
        let ninv = self.inv(b.len() as i64);
        for i in b.iter_mut() {
            *i = *i * ninv % self.m;
        }
        b
    }

    pub fn convolution(&self, mut a: Vec<i64>, mut b: Vec<i64>) -> Vec<i64> {
        let n = (a.len() + b.len()).max(1) - 1;
        a.resize(n, 0);
        b.resize(n, 0);
        let x = self.ntt(a);
        let y = self.ntt(b);
        let z = x.into_iter().zip(y).map(|(i, j)| i * j % self.m).collect();
        let mut c = self.intt(z);
        while let Some(&0) = c.last() {
            c.pop();
        }
        c
    }

    pub fn poly_pow(&self, mut a: Vec<i64>, b: i64) -> Vec<i64> {
        if a.is_empty() {
            a
        } else if b == 0 {
            vec![1]
        } else if b == 1 {
            a
        } else {
            let n = (a.len() - 1) * b as usize + 1;
            a.resize(n, 0);
            a = self.ntt(a);
            for i in a.iter_mut() {
                *i = self.pow(*i, b);
            }
            self.intt(a)
        }
    }
}

#[derive(Eq)]
struct ByLen(Vec<i64>);

impl PartialOrd for ByLen {
    fn partial_cmp(&self, other: &Self) -> Option<cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for ByLen {
    fn cmp(&self, other: &Self) -> cmp::Ordering {
        other.0.len().cmp(&self.0.len())
    }
}

impl PartialEq for ByLen {
    fn eq(&self, other: &Self) -> bool {
        self.0.len() == other.0.len()
    }
}

fn main() {
    let n = read_line().trim().parse().unwrap();
    let mut d = vec![0; n];
    d[0] += 1;
    for _ in 1..n {
        if let [a, b] = read_vec::<usize>()[..] {
            d[a - 1] += 1;
            d[b - 1] += 1;
        }
    }
    // eprintln!("{:?}", d);

    /*
    let mut dp = vec![0; n];
    dp[0] = 1;
    for &i in &d {
        for j in (1..n).rev() {
            dp[j] += dp[j - 1] * (i - 1);
        }
    }
    eprintln!("{:?}", dp);
    */

    let mut c = HashMap::new();
    for &i in &d {
        *c.entry(i).or_insert(0) += 1;
    }

    const MOD: i64 = 998244353;
    let m = Modulo::new(MOD);
    let mut pq = BinaryHeap::new();
    for (i, j) in c {
        pq.push(ByLen(m.poly_pow(vec![1, i - 1], j)));
    }
    while pq.len() > 1 {
        let a = pq.pop().unwrap().0;
        let b = pq.pop().unwrap().0;
        pq.push(ByLen(m.convolution(a, b)));
    }
    let mut dp = pq.pop().unwrap().0;
    dp.resize(n, 0);
    // eprintln!("{:?}", dp);

    let mut ans = 0;
    let mut fact = 1;
    for i in 1..=n {
        fact = fact * i as i64 % MOD;
        if (n - i) % 2 == 0 {
            ans += dp[n - i] * fact % MOD;
        } else {
            ans -= dp[n - i] * fact % MOD;
        }
    }
    println!("{}", ans.rem_euclid(MOD));
}

// 143478135	Jan/20/2022 21:00UTC-8	watashi	1613F - Tree Coloring	Rust 2021	Accepted	1778 ms	22300 KB
