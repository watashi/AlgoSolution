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
        if let [_, l, r, mut k] = read_vec::<u32>()[..] {
            let mut a = read_vec::<u32>();
            a.sort();
            let mut c = 0;
            for i in a {
                if i >= l && i <= r && i <= k {
                    k -= i;
                    c += 1;
                }
            }
            println!("{}", c);
        }
    }
}

// 141349372	Jan/01/2022 12:32UTC-8	watashi	1614A - Divan and a Store	Rust 2021	Happy New Year!	0 ms	0 KB
