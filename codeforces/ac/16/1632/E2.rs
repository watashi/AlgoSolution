use std::*;

pub struct RMQ<T> {
    index: Vec<Vec<usize>>,
    value: Vec<T>,
}

impl<T: Ord> RMQ<T> {
    fn min(v: &Vec<T>, i: usize, j: usize) -> usize {
        if v[i].cmp(&v[j]).is_ge() {
            i
        } else {
            j
        }
    }

    pub fn new(value: Vec<T>) -> Self {
        let mut index = vec![];
        let mut prev = (0..value.len()).collect::<Vec<_>>();
        let mut step = 1;
        while !prev.is_empty() {
            let next = prev
                .iter()
                .zip(prev.iter().skip(step))
                .map(|(&i, &j)| Self::min(&value, i, j))
                .collect();
            index.push(prev);
            prev = next;
            step *= 2;
        }
        RMQ {
            index: index,
            value: value,
        }
    }

    pub fn index(&self, start: usize, end: usize) -> usize {
        let n = (usize::BITS - (end - start).leading_zeros() - 1) as usize;
        Self::min(
            &self.value,
            self.index[n][start],
            self.index[n][end - (1 << n)],
        )
    }

    pub fn value(&self, start: usize, end: usize) -> &T {
        &self.value[self.index(start, end)]
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

fn dfs(v: usize, p: usize, e: &Vec<Vec<usize>>, info: &mut Vec<(usize, i32, i32)>) -> i32 {
    let (mut d, mut d2) = (0, 0);
    for &w in &e[v] {
        if w != p {
            let dw = dfs(w, v, e, info) + 1;
            if dw > d {
                d2 = d;
                d = dw;
            } else if dw > d2 {
                d2 = dw;
            }
        }
    }
    info[v] = (p, d, d2);
    d
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let mut e = vec![vec![]; n];
        for _ in 1..n {
            if let [a, b] = read_vec::<usize>()[..] {
                e[a - 1].push(b - 1);
                e[b - 1].push(a - 1);
            }
        }
        let mut info = vec![(0, 0, 0); n];
        dfs(0, 0, &e, &mut info);
        let mut v = 0;
        let mut chain = vec![info[v].2];
        while info[v].1 > 0 {
            v = e[v]
                .iter()
                .copied()
                .find(|&i| info[i].1 == info[v].1 - 1)
                .unwrap();
            chain.push(info[v].2);
        }

        let left = RMQ::new(
            chain
                .iter()
                .enumerate()
                .map(|(i, j)| *j + i as i32)
                .collect(),
        );
        let right = RMQ::new(
            chain
                .iter()
                .enumerate()
                .map(|(i, j)| *j - i as i32)
                .collect(),
        );
        let dist = |x, i| {
            let m = (x + i + 1) / 2;
            let mut ret = (chain.len() - i - 1 + x) as i32;
            ret = ret.max(*left.value(0, m));
            ret = ret.max(*right.value(m, i + 1) + (i + x) as i32);
            ret
        };

        let mut ans = vec![];
        let (mut y, mut yi) = (info[0].1, 0);
        for i in 2..chain.len() {
            let yy = dist(1, i);
            if yy < y {
                y = yy;
                yi = i;
            }
        }
        ans.push(y.to_string());
        for x in 2..=n {
            if y < info[0].1 && y < dist(x, yi) {
                y += 1;
                if yi + 1 < chain.len() && dist(x, yi + 1) < y {
                    y -= 1;
                    yi += 1;
                }
            }
            ans.push(y.to_string());
        }
        println!("{}", ans.join(" "));
    }
}

// 149569471	Mar/13/2022 18:10UTC-7	watashi	1632E2 - Distance Tree (hard version)	Rust 2021	Accepted	342 ms	166800 KB
