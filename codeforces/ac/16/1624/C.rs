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
        let a = read_vec::<usize>();
        let n = a.len();
        let mut p = vec![0; n + 1];
        for mut i in a {
            while i > n {
                i >>= 1;
            }
            p[i] += 1;
        }
        let mut ans = "YES";
        for i in (1..=n).rev() {
            if p[i] == 0 {
                ans = "NO";
                break;
            }
            p[i >> 1] += p[i] - 1;
        }
        println!("{}", ans);
    }
}

// 143811004	Jan/23/2022 10:00UTC-8	watashi	1624C - Division by Two and Permutation	Rust 2021	Accepted	155 ms	200 KB
