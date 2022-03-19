use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let s = read_line();
        let c0 = s.as_bytes().iter().filter(|&&i| i == b'0').count();
        let c1 = s.as_bytes().iter().filter(|&&i| i == b'1').count();
        println!("{}", if c0 == c1 { c0 - 1 } else { c0.min(c1) });
    }
}

// 150180480	Mar/19/2022 16:01UTC-7	watashi	1633B - Minority	Rust 2021	Accepted	92 ms	800 KB
