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
        let m = read_vec::<usize>()[1];
        let x = read_vec::<u32>();
        let n = x.len();
        let mut c = vec![0; m];
        for mut i in x {
            for j in c.iter_mut() {
                *j += i & 1;
                i >>= 1;
            }
        }
        let mut y = 0;
        for i in c.into_iter().rev() {
            y <<= 1;
            if i * 2 > n as u32 {
                y |= 1;
            }
        }
        println!("{}", y);
    }
}

// 143946189	Jan/24/2022 23:57UTC-8	watashi	1625A - Ancient Civilization	Rust 2021	Accepted	0 ms	100 KB
