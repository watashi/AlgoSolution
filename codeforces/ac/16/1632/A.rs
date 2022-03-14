use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    const OK: [&str; 4] = ["0", "1", "01", "10"];
    const YES: [&str; 2] = ["NO", "YES"];
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let s = read_line();
        println!("{}", YES[OK.iter().any(|i| i == &s.trim()) as usize]);
    }
}

// 149574777	Mar/13/2022 21:04UTC-7	watashi	1632A - ABC	Rust 2021	Accepted	15 ms	0 KB
