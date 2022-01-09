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

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let n = read_line().trim().parse().unwrap();
        let mut ans = vec![String::new(); n];
        let mut hm = HashMap::<_, Vec<_>>::new();
        for i in ans.iter_mut() {
            if let [a, b, m] = read_vec::<i32>()[..] {
                hm.entry(a + b - m).or_default().push((a, a - m, i));
            }
        }
        let mut c = hm.len();
        for (&k, v) in &mut hm {
            v.sort_unstable_by_key(|i| i.0);
            let mut a = cmp::min(v[0].0, k);
            for (i, j, r) in v {
                if *j > a {
                    c += 1;
                    a = cmp::min(*i, k);
                }
                **r = format!("{} {}", *i - a, a - *j);
            }
        }
        println!("{}\n{}", c, ans[..].join("\n"));
    }
}

// 141619039	Jan/04/2022 00:19UTC-8	watashi	1607H - Banquet Preparations 2	Rust 2021	Happy New Year!	265 ms	31200 KB
