use std::*;

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
        self.p[x] = y;
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
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let nm = read_vec::<usize>();
        let n = nm[0];
        let mut e = (0..nm[1])
            .map(|i| {
                let x = read_vec::<usize>();
                (x[2], x[0] - 1, x[1] - 1)
            })
            .collect::<Vec<_>>();
        e.sort_unstable();

        let mut maxe = {
            let mut maxe = 0;
            let mut rem = n;
            let mut ds = DisjointSet::new(n);
            for &(k, i, j) in &e {
                if ds.setp(i, j).is_some() {
                    rem -= 1;
                    if rem == 1 {
                        maxe = k;
                        break;
                    }
                }
            }
            while maxe.count_ones() > 1 {
                maxe = maxe & (maxe - 1);
            }
            maxe
        };

        for bit in (0..maxe.trailing_zeros()).rev() {
            let mut rem = n;
            let mut ds = DisjointSet::new(n);
            for &(k, i, j) in &e {
                if (k >> bit) & (maxe >> bit) == (k >> bit) && ds.setp(i, j).is_some() {
                    rem -= 1;
                    if rem == 1 {
                        break;
                    }
                }
            }
            if rem > 1 {
                maxe |= 1 << bit;
            }
        }
        println!("{}", maxe);
    }
}

// 143744976	Jan/22/2022 22:45UTC-8	watashi	1624G - MinOr Tree	Rust 2021	Accepted	249 ms	6200 KB
