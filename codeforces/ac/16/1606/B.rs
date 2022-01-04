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
        if let [n, k] = read_vec::<u64>()[..] {
            let (mut m, mut t) = (1, 0);
            while m < n && m < k {
                m <<= 1;
                t += 1;
            }
            if m < n {
                t += (n - m + k - 1) / k;
            }
            writeln!(cout, "{}", t).ok();
        }
    }
}

// 141596506	Jan/03/2022 18:47UTC-8	watashi	1606B - Update Files	Rust 2021	Happy New Year!	61 ms	0 KB
