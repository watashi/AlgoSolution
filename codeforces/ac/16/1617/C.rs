use std::{collections::*, *};

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
    let mut ans = vec![];
    for _ in 0..re {
        read_line();
        let mut p = read_vec::<usize>();
        let mut q = VecDeque::new();
        let mut r = p.len() as i32;
        p.sort_unstable();
        let mut it = p.iter().rev().peekable();
        for i in (1..=p.len()).rev() {
            while let Some(&&j) = it.peek() {
                if j > i {
                    q.push_back((j - 1) / 2);
                    it.next();
                } else if j == i {
                    r -= 1;
                    q.push_front(j);
                    it.next();
                    break;
                } else {
                    break;
                }
            }
            match q.pop_front() {
                Some(j) if j >= i => {}
                _ => {
                    r = -1;
                    break;
                }
            }
        }
        ans.push(r.to_string());
    }
    println!("{}", ans[..].join("\n"));
}

// 140880151	Dec/28/2021 01:54UTC-8	watashi	1617C - Paprika and Permutation	Rust 2021	Happy New Year!	31 ms	4100 KB
