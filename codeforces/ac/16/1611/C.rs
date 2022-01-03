use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec() -> Vec<usize> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn join<T>(a: impl IntoIterator<Item = T>, b: &str) -> String
where
    T: string::ToString,
{
    a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(b)
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let mut a = read_vec();
        if a[0] == n {
            a[1..].reverse();
        } else if a[n - 1] == n {
            a[0..n - 1].reverse();
        } else {
            a.clear();
        }
        if a.is_empty() {
            println!("-1");
        } else {
            println!("{}", join(a, " "));
        }
    }
}

// 141382444	Jan/02/2022 01:23UTC-8	watashi	1611C - Polycarp Recovers the Permutation	Rust 2021	Happy New Year!	93 ms	9900 KB
