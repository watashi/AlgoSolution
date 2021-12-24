use std::io::*;

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
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
    a.sort_unstable();

    let mut xtot = 0;
    let query = {
        let (mut xcnt, mut xsum, mut cnt, mut sum) = (0, 0, vec![0], vec![0]);
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
            sum[to] - sum[to - c as usize]
        }
    };

    let mut gaps: Vec<(i64, usize)> = vec![];
    for i in 1..a.len() {
        gaps.push((a[i].0 - a[i - 1].0, i));
    }
    gaps.sort_unstable();

    let mut prev: Vec<usize> = (0..a.len()).collect();
    let mut next = prev.clone();
    let mut ans: Vec<(i64, i64)> = vec![];
    let mut gap: i64 = -1;
    for (k, i) in gaps {
        if k != gap {
            ans.push((gap, xtot));
            gap = k;
        }
        xtot -= query(prev[i - 1], i);
        xtot -= query(i, next[i] + 1);
        xtot += query(prev[i - 1], next[i] + 1);
        next[prev[i - 1]] = next[i];
        prev[next[i]] = prev[i - 1];
    }
    ans.push((gap, xtot));

    let mut stdout = BufWriter::new(stdout());
    for i in read_vec::<i64>() {
        let k = ans.binary_search(&(i + 1, -1)).map_or_else(|x| x, |x| x);
        writeln!(stdout, "{}", ans[k - 1].1).unwrap();
    }
}

// 140414459	Dec/23/2021 23:45UTC-8	watashi	1618G - Trader Problem	Rust 2021	Accepted	171 ms	30700 KB
