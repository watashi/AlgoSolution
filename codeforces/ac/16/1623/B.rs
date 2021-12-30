use std::{io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
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
    let mut cout = BufWriter::new(stdout());
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let mut mark = vec![false; n + 1];
        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            let i = read_vec::<usize>();
            a.push((i[0], i[1]));
        }
        a.sort_unstable_by_key(|&(l, r)| r - l);
        for (l, r) in a {
            for i in l..=r {
                if !mark[i] {
                    mark[i] = true;
                    writeln!(cout, "{} {} {}", l, r, i).ok();
                    break;
                }
            }
        }
    }
}

// 141141502	Dec/30/2021 01:12UTC-8	watashi	1623B - Game on Ranges	Rust 2021	Happy New Year!	15 ms	0 KB
