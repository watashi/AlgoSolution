use std::*;

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

fn join<T>(a: impl IntoIterator<Item = T>, b: &str) -> String
where
    T: string::ToString,
{
    a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(b)
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [n, a, b] = read_vec::<i64>()[..] {
            let mut p = vec![];
            let m = n / 2;
            if a == m + 1 && b == m {
                p.extend((1..=n).rev());
            } else if a <= m && b >= m + 1 {
                p.extend(b + 1..=n);
                p.extend(a..=b);
                p.extend(1..a);
            } else {
                p.push(-1);
            }
            println!("{}", join(p, " "));
        }
    }
}

// 141471939	Jan/03/2022 01:52UTC-8	watashi	1612B - Special Permutation	Rust 2021	Happy New Year!	31 ms	100 KB
