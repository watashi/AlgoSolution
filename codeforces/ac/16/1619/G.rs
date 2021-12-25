use std::{collections::*, io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

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

fn main() {
    let re: i64 = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let nk = read_vec::<i64>();
        let (n, k) = (nk[0] as usize, nk[1]);

        type ByLine = HashMap<i64, Vec<(i64, usize)>>;
        let add = |m: &mut ByLine, k, v| match m.get_mut(&k) {
            Some(vs) => vs.push(v),
            None => {
                m.insert(k, vec![v]);
            }
        };
        let mut byx = HashMap::new();
        let mut byy = HashMap::new();
        let mut mint = vec![];
        for i in 0..n {
            if let [x, y, t] = read_vec::<i64>()[..] {
                add(&mut byx, x, (y, i));
                add(&mut byy, y, (x, i));
                mint.push(t);
            }
        }

        let mut ds = DisjointSet::new(n);
        let mut process = |mut m: ByLine| {
            for vs in m.values_mut() {
                vs.sort_unstable();
                for i in 1..vs.len() {
                    if vs[i].0 <= vs[i - 1].0 + k {
                        if let Some((x, y)) = ds.setp(vs[i].1, vs[i - 1].1) {
                            mint[y] = cmp::min(mint[x], mint[y]);
                        }
                    }
                }
            }
        };
        process(byx);
        process(byy);

        let mut past = 0;
        let mut groups: Vec<usize> = (0..n)
            .filter(|&i| ds.getp(i) == i)
            .map(|i| mint[i] as usize)
            .collect();
        groups.sort_unstable();
        for now in 0..groups.len() {
            while past < groups.len() && groups[past] <= now {
                past += 1;
            }
            if now + past + 1 >= groups.len() {
                println!("{}", now);
                break;
            }
        }
    }
}

// 140538071	Dec/24/2021 20:28UTC-8	watashi	1619G - Unusual Minesweeper	Rust 2021	Happy New Year!	187 ms	33600 KB
