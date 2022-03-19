use std::*;

pub struct DisjointSet(Vec<usize>);

impl DisjointSet {
    pub fn new(n: usize) -> Self {
        DisjointSet((0..n).collect())
    }

    pub fn clear(&mut self) {
        self.0.iter_mut().enumerate().for_each(|(i, j)| *j = i);
    }

    pub fn getp(&mut self, x: usize) -> usize {
        if self.0[x] != x {
            self.0[x] = self.getp(self.0[x]);
        }
        self.0[x]
    }

    pub fn setp(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        let x = self.getp(x);
        let y = self.getp(y);
        self.0[x] = y;
        if x != y {
            Some((x, y))
        } else {
            None
        }
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
    let [n, m]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
    let mut e = Vec::with_capacity(m);
    for _ in 0..m {
        if let [u, v, w] = read_vec::<usize>()[..] {
            e.push((w as i64, u - 1, v - 1));
        }
    }

    let mut xs = vec![0];
    for i in e.iter() {
        xs.push(i.0);
        for j in e.iter() {
            xs.push((i.0 + j.0) / 2 + 1);
        }
    }
    xs.sort_unstable();
    xs.dedup();

    let ys = xs
        .into_iter()
        .map(|x| {
            let mut ds = DisjointSet::new(n);
            let (mut a, mut b, mut c) = (0, 0, n - 1);
            e.sort_unstable_by_key(|&i| (i.0 - x).abs());
            for &(w, u, v) in &e {
                if ds.setp(u, v).is_some() {
                    a += (x - w).signum();
                    b += (x - w).abs();
                    c -= 1;
                    if c == 0 {
                        break;
                    }
                }
            }
            (x, a, b)
        })
        .collect::<Vec<_>>();
    let mst = |q| {
        let (x, a, b) = ys[ys.binary_search(&(q, i64::MAX, i64::MAX)).unwrap_err() - 1];
        a * (q - x) + b
    };

    let mut ans = 0;
    let [p, k, a, b, c]: [i64; 5] = read_vec::<i64>().try_into().unwrap();
    let mut q = 0;
    for i in read_vec::<i64>() {
        q = i;
        ans ^= mst(q);
    }
    for _ in p..k {
        q = (q * a + b) % c;
        ans ^= mst(q);
    }
    println!("{}", ans);
}

// 150178663	Mar/19/2022 15:10UTC-7	watashi	1633E - Spanning Tree Queries	Rust 2021	Accepted	1294 ms	5100 KB
