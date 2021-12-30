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
        read_line();
        let h = read_vec::<i64>();
        let (mut lo, mut hi) = (0, h.iter().sum::<i64>() + 1);
        'bsearch: while lo < hi {
            let mi = (lo + hi) / 2;
            let (mut a, mut b) = (0, 0);
            for (i, &x) in h.iter().enumerate().rev() {
                if x + a < mi {
                    hi = mi;
                    continue 'bsearch;
                } else {
                    let d = if i < 2 {
                        0
                    } else {
                        cmp::min(x, x + a - mi) / 3
                    };
                    a = b + d;
                    b = 2 * d;
                }
            }
            lo = mi + 1;
        }
        writeln!(cout, "{}", hi - 1).ok();
    }
}

// 141142876	Dec/30/2021 01:30UTC-8	watashi	1623C - Balanced Stone Heaps	Rust 2021	Happy New Year!	61 ms	7700 KB
