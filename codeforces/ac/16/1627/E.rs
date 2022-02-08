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

fn dist(d: &Vec<(usize, i64)>, i: usize, x: i64) -> i64 {
    match d.binary_search_by(|j| j.0.cmp(&i)) {
        Ok(k) => d[k].1,
        Err(k) => {
            let mut ret = i64::MIN;
            if k > 0 {
                ret = d[k - 1].1 - (i - d[k - 1].0) as i64 * x;
            }
            if k < d.len() {
                ret = ret.max(d[k].1 - (d[k].0 - i) as i64 * x);
            }
            ret
        }
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let [n, m, k]: [usize; 3] = read_vec::<usize>().try_into().unwrap();
        let x = read_vec::<i64>();
        let mut e = vec![vec![]; n];
        for _ in 0..k {
            if let [a, b, c, d, h] = read_vec::<usize>()[..] {
                e[c - 1].push((a - 1, b - 1, d - 1, h as i64));
            }
        }

        let mut d = Vec::with_capacity(n);
        d.push(vec![(0, 0)]);
        for (i, ei) in e.into_iter().enumerate().skip(1) {
            let mut di = BTreeMap::<_, i64>::new();
            for (j, jj, ii, h) in ei {
                if !d[j].is_empty() {
                    let dd = dist(&d[j], jj, x[j]) + h;
                    di.entry(ii).and_modify(|v| *v = dd.max(*v)).or_insert(dd);
                }
            }
            let mut di = di.into_iter().collect::<Vec<_>>();
            let mut pq = BinaryHeap::new();
            for (ii, &(_, dii)) in di.iter().enumerate() {
                pq.push((dii, ii));
            }
            while let Some((dii, ii)) = pq.pop() {
                if di[ii].1 == dii {
                    if ii > 0 {
                        let djj = dii - (di[ii].0 - di[ii - 1].0) as i64 * x[i];
                        if di[ii - 1].1 < djj {
                            di[ii - 1].1 = djj;
                            pq.push((djj, ii - 1));
                        }
                    }
                    if ii + 1 < di.len() {
                        let djj = dii - (di[ii + 1].0 - di[ii].0) as i64 * x[i];
                        if di[ii + 1].1 < djj {
                            di[ii + 1].1 = djj;
                            pq.push((djj, ii + 1));
                        }
                    }
                }
            }
            d.push(di);
        }

        if d[n - 1].is_empty() {
            println!("NO ESCAPE");
        } else {
            println!("{}", -dist(&d[n - 1], m - 1, x[n - 1]));
        }
    }
}

// 145513299	Feb/07/2022 00:02UTC-8	watashi	1627E - Not Escaping	Rust 2021	Accepted	467 ms	23000 KB
