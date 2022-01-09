use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let c2i = |c: char| c as usize - 'a' as usize;
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let mut p = [0; 26];
        for (i, c) in read_line().trim().chars().enumerate() {
            p[c2i(c)] = i as i32;
        }
        let s = read_line();
        let ans: i32 = s
            .trim()
            .chars()
            .skip(1)
            .zip(s.chars())
            .map(|(i, j)| (p[c2i(i)] - p[c2i(j)]).abs())
            .sum();
        println!("{}", ans);
    }
}

// 141962695	Jan/07/2022 21:10UTC-8	watashi	1607A - Linear Keyboard	Rust 2021	Happy New Year!	15 ms	0 KB
