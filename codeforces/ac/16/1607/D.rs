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
        let n = read_line().trim().parse().unwrap();
        let a = read_vec::<i32>();
        let (mut r, mut b) = a
            .into_iter()
            .zip(read_line().chars())
            .partition::<Vec<_>, _>(|i| i.1 == 'R');
        r.sort_unstable();
        b.sort_unstable();
        let yes = r.iter().rev().zip((1..=n).rev()).all(|(i, j)| i.0 <= j)
            && b.iter().zip(1..=n).all(|(i, j)| i.0 >= j);
        println!("{}", if yes { "YES" } else { "NO" });
    }
}

// 141870964	Jan/06/2022 19:58UTC-8	watashi	1607D - Blue-Red Permutation	Rust 2021	Happy New Year!	124 ms	6100 KB
