use std::{cmp::Ordering::*, collections::*, *};

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

type Cost = (i64, i64, i64);
type Query<'a> = HashMap<usize, Vec<(i64, &'a mut String)>>;

// Vec<Cost> invariants:
// * x[0].0 = 0
// * x[i].0 is increasing
// * x[i].1 is decreasing
// * x[i].2 is decreasing
// * x.last() = Some((_, 0, 1))
// * x.len() <= O(sqrt(n))
fn merge(xs: &Vec<Vec<Cost>>) -> Vec<Cost> {
    if xs.is_empty() {
        return vec![(0, 0, 0)];
    }

    let mut bh = (0..xs.len()).map(|i| (0, i, 0)).collect::<BinaryHeap<_>>();
    let (mut a, mut b) = (0, 0);
    let mut y = vec![];
    while !bh.is_empty() {
        let k = bh.peek().unwrap().0;
        while let Some(&(k0, i, j)) = bh.peek() {
            if k0 != k {
                break;
            }
            let x = &xs[i];
            a += x[j].1 - if j == 0 { 0 } else { x[j - 1].1 };
            b += x[j].2 - if j == 0 { 0 } else { x[j - 1].2 };
            bh.pop();
            if let Some(&(k1, _, _)) = x.get(j + 1) {
                bh.push((-k1, i, j + 1));
            }
        }
        y.push((-k, a, b));
    }
    y
}

fn gao(e: &Vec<Vec<usize>>, q: &mut Query, v: usize, p: usize) -> Vec<Cost> {
    let mut x = Vec::with_capacity(e[v].len());
    for &w in &e[v] {
        if w != p {
            x.push(gao(e, q, w, v));
        }
    }
    let mut x = merge(&x);

    if let Some(q) = q.get_mut(&v) {
        for (k, r) in q {
            let pos = x.binary_search_by_key(k, |i| i.0);
            let (_, a, b) = x[pos.unwrap_or_else(|i| i - 1)];
            **r = cmp::max(0, b - a * *k).to_string();
        }
    }

    for i in &mut x {
        i.1 += 1;
    }
    while let Some(&(k, a, b)) = x.last() {
        if b - k * a <= 1 {
            x.pop();
        } else {
            break;
        }
    }
    let kk = match x.last() {
        Some(&(_, a, b)) => (b - 1 + a - 1) / a,
        None => 0,
    };
    x.push((kk, 0, 1));
    x
}

fn main() {
    let n = read_line().trim().parse().unwrap();
    let mut e = vec![vec![]; n];
    for _ in 1..n {
        if let [x, y] = read_vec::<usize>()[..] {
            e[x - 1].push(y - 1);
            e[y - 1].push(x - 1);
        }
    }
    let m = read_line().trim().parse().unwrap();
    let mut r = vec![String::new(); m];
    let mut q: Query = HashMap::new();
    for i in &mut r {
        if let [v, k] = read_vec::<usize>()[..] {
            q.entry(v - 1).or_default().push((k as i64, i));
        }
    }
    gao(&e, &mut q, 0, 0);
    println!("{}", r[..].join("\n"));
}

// 141591588	Jan/03/2022 15:40UTC-8	watashi	1606F - Tree Queries	Rust 2021	Happy New Year!	451 ms	117400 KB
