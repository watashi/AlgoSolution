use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let mut s = read_line().trim().chars().collect::<Vec<_>>();
        let n = s.len();
        if s.first() != s.last() {
            *s.last_mut().unwrap() = s[0];
        }
        println!("{}", s.iter().collect::<String>());
    }
}

// 141600873	Jan/03/2022 20:29UTC-8	watashi	1606A - AB Balance	Rust 2021	Happy New Year!	15 ms	0 KB
