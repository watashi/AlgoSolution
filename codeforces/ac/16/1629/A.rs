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
        let mut k = read_vec::<usize>()[1];
        let a = read_vec::<usize>();
        let b = read_vec::<usize>();
        let mut ab = a.into_iter().zip(b).collect::<Vec<_>>();
        ab.sort_unstable();
        for (i, j) in ab {
            if k >= i {
                k += j;
            }
        }
        println!("{}", k);
    }
}

// 147224344	Feb/21/2022 17:32UTC-8	watashi	1629A - Download More RAM	Rust 2021	Accepted	15 ms	100 KB
