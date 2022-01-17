use std::{collections::*, *};

struct DisjointSet {
    p: Vec<usize>,
}

impl DisjointSet {
    fn new(n: usize) -> DisjointSet {
        DisjointSet {
            p: (0..n).collect(),
        }
    }

    fn getp(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.getp(self.p[x]);
        }
        self.p[x]
    }

    fn setp(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        let x = self.getp(x);
        let y = self.getp(y);
        if x != y {
            self.p[x] = y;
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
    let nd = read_vec::<usize>();
    let (n, d) = (nd[0], nd[1]);
    let mut ds = DisjointSet::new(n);
    let mut sz = vec![1; n];
    let mut tm = BTreeSet::from_iter(iter::repeat(1).zip(0..n));
    let mut z = 1;
    for _ in 0..d {
        if let [x, y] = read_vec::<usize>()[..] {
            let x = ds.getp(x - 1);
            let y = ds.getp(y - 1);
            if x != y {
                ds.setp(x, y);
                tm.remove(&(sz[x], x));
                tm.remove(&(sz[y], y));
                sz[y] += sz[x];
                tm.insert((sz[y], y));
            } else {
                z += 1;
            }
            println!(
                "{}",
                tm.iter().rev().take(z).map(|i| i.0).sum::<usize>() - 1
            );
        }
    }
}

// 143071431	Jan/16/2022 22:34UTC-8	watashi	1609D - Social Network	Rust 2021	Accepted	31 ms	100 KB
