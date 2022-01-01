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
        let t = read_line();
        let mut cs = s.trim().chars().collect::<Vec<_>>();
        if "abc".chars().all(|c| s.find(c).is_some()) && t.trim() == "abc" {
            cs.sort_unstable_by_key(|&c| {
                if c == 'b' {
                    'c'
                } else if c == 'c' {
                    'b'
                } else {
                    c
                }
            });
        } else {
            cs.sort_unstable();
        }
        println!("{}", cs.iter().collect::<String>());
    }
}

// 140875504	Dec/28/2021 01:00UTC-8	watashi	1617A - Forbidden Subsequence	Rust 2021	Happy New Year!	31 ms	100 KB
