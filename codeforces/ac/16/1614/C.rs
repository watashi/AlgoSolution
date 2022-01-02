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
    const M: u64 = 1_000_000_007;
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let nm = read_vec::<u64>();
        let mut b = 1;
        for _ in 1..nm[0] {
            b = b * 2 % M;
        }
        let mut m = 0;
        for _ in 0..nm[1] {
            m |= read_vec::<u64>()[2];
        }
        let mut s = 0;
        for i in 0..u64::BITS {
            if (m >> i) & 1 != 0 {
                s = (s + b) % M;
            }
            b = b * 2 % M;
        }
        println!("{}", s);
    }
}

// 141348188	Jan/01/2022 12:07UTC-8	watashi	1614C - Divan and bitwise operations	Rust 2021	Happy New Year!	78 ms	0 KB
