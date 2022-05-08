use std::*;

pub struct RMQ<T> {
    index: Vec<Vec<usize>>,
    value: Vec<T>,
}

impl<T: Ord> RMQ<T> {
    fn min(v: &Vec<T>, i: usize, j: usize) -> usize {
        if v[i].cmp(&v[j]).is_le() {
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

fn segtree_build(pairs: Vec<Vec<(usize, i64)>>) -> (usize, Vec<Vec<(usize, i64)>>) {
    let mut n = 1;
    while n < pairs.len() {
        n <<= 1;
    }
    let mut v = vec![vec![]; n];
    v.extend(pairs);
    for i in (1..v.len()).rev() {
        v[i].sort_unstable();
        v[i].dedup_by(|i, j| i.1 >= j.1);
        if i > 1 {
            let (l, r) = v.split_at_mut(i);
            l[i >> 1].extend(&r[0]);
        }
    }
    (n, v)
}

fn segtree_query(
    v: &Vec<Vec<(usize, i64)>>,
    p: usize,
    pl: usize,
    pr: usize,
    l: usize,
    r: usize,
    x: usize,
) -> i64 {
    let mut ret = i64::MAX;
    if pl == l && pr == r {
        let i = v[p].binary_search(&(x + 1, -1)).unwrap_err();
        if i > 0 {
            ret = v[p][i - 1].1;
        }
    } else {
        let pm = (pl + pr) / 2;
        if l < pm {
            ret = segtree_query(v, p * 2, pl, pm, l, r.min(pm), x).min(ret);
        }
        if pm < r {
            ret = segtree_query(v, p * 2 + 1, pm, pr, l.max(pm), r, x).min(ret);
        }
    }
    ret
}

fn main() {
    let [n, q]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
    let mut v = Vec::with_capacity(n);
    for _ in 0..n {
        if let [x, w] = read_vec::<i64>()[..] {
            v.push((x, w));
        }
    }
    let v = v;
    let rmq = RMQ::new(v.iter().map(|i| i.1).collect());

    let mut pairs = vec![vec![]; n];
    let mut dfs = vec![(0, n)];
    while let Some((l, r)) = dfs.pop() {
        if r - l == 1 {
            continue;
        }
        pairs[l].push((r, (v[r - 1].0 - v[l].0) * (v[l].1 + v[r - 1].1)));
        if r - l == 2 {
            continue;
        }
        let m = rmq.index(l + 1, r - 1);
        dfs.push((l, m + 1));
        dfs.push((m, r));
    }

    let (nt, t) = segtree_build(pairs);
    let mut ans = vec![];
    for _ in 0..q {
        if let [l, r] = read_vec::<usize>()[..] {
            ans.push(segtree_query(&t, 1, 0, nt, l - 1, r, r).to_string());
        }
    }
    println!("{}", ans.join("\n"));
}

// 150422215	Mar/21/2022 23:25UTC-7	watashi	1635F - Closest Pair	Rust 2021	Accepted	826 ms	160000 KB
