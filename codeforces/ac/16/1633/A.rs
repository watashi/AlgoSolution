use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let mut n: i32 = read_line().trim().parse().unwrap();
        let r = n % 7;
        if r > n % 10 {
            n += 7 - r;
        } else {
            n -= r;
        }
        println!("{}", n);
    }
}

// 150180609	Mar/19/2022 16:05UTC-7	watashi	1633A - Div. 7	Rust 2021	Accepted	15 ms	0 KB
