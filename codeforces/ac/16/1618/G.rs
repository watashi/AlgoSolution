use std::collections::*;
use std::convert::*;

fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .trim()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    read_line();
    let mut a: Vec<(i64, bool)> = Vec::new();
    for i in read_vec::<i64>() {
        a.push((i, true));
    }
    for i in read_vec::<i64>() {
        a.push((i, false));
    }
    a.sort();

    let mut xtot = 0;
    let query = {
        let (mut xcnt, mut xsum, mut cnt, mut sum) = (0usize, 0, vec![0usize], vec![0]);
        for i in &a {
            xsum += i.0;
            if i.1 {
                xcnt += 1;
                xtot += i.0;
            }
            cnt.push(xcnt);
            sum.push(xsum);
        }
        move |from, to| {
            let c = cnt[to] - cnt[from];
            sum[to] - sum[to - c]
        }
    };

    let mut m: BTreeMap<i64, Vec<usize>> = BTreeMap::new();
    for i in 1..a.len() {
        let k = a[i].0 - a[i - 1].0;
        match m.get_mut(&k) {
            Some(v) => v.push(i),
            None => {
                m.insert(k, vec![i]);
            }
        }
    }

    let mut prev: Vec<usize> = (0..a.len()).collect();
    let mut next = prev.clone();
    let mut ans: Vec<(i64, i64)> = vec![];
    ans.push((-1, xtot));
    for (k, v) in m {
        for i in v {
            xtot -= query(prev[i - 1], i);
            xtot -= query(i, next[i] + 1);
            xtot += query(prev[i - 1], next[i] + 1);
            next[prev[i - 1]] = next[i];
            prev[next[i]] = prev[i - 1];
        }
        ans.push((k, xtot));
    }

    for i in read_vec::<i64>() {
        let k = ans
            .binary_search(&(i + 1, -1))
            .map_or_else(identity, identity);
        println!("{}", ans[k - 1].1);
    }
}

// 140412263	Dec/23/2021 23:14UTC-8	watashi	1618G - Trader Problem	Rust 2021	Accepted	1762 ms	31800 KB
