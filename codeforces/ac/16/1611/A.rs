use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    let even = |x| x % 2 == b'0' % 2;
    for _ in 0..re {
        let n = read_line();
        let s = n.trim().as_bytes();
        let ans = if even(s[s.len() - 1]) {
            0
        } else {
            match s.iter().copied().position(even) {
                Some(0) => 1,
                Some(_) => 2,
                None => -1,
            }
        };
        println!("{}", ans);
    }
}

// 141383520	Jan/02/2022 01:36UTC-8	watashi	1611A - Make Even	Rust 2021	Happy New Year!	93 ms	0 KB
