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

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let mut a = read_vec::<i64>()
            .iter()
            .enumerate()
            .map(|(i, j)| (*j, i))
            .collect::<Vec<_>>();
        a.sort_unstable();
        let mut x = vec![String::new(); a.len()];
        let mut s = 0;
        for (d, &(c, i)) in a.iter().rev().enumerate() {
            let mut k = (d / 2 + 1) as i64;
            s += k * c;
            if d % 2 != 0 {
                k = -k;
            }
            x[i] = k.to_string();
        }
        println!("{}\n0 {}", 2 * s, x[..].join(" "));
    }
}

// 141349144	Jan/01/2022 12:27UTC-8	watashi	1614B - Divan and a New Project	Rust 2021	Happy New Year!	46 ms	12200 KB
