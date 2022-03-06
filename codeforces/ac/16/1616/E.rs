use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn dist(next: &Vec<Vec<usize>>, x: usize) -> usize {
    next.iter()
        .map(|v| v.len() - v.binary_search_by(|i| x.cmp(i)).unwrap_or_else(|i| i))
        .sum::<usize>()
}

fn gao(s: &[u8], t: &[u8]) -> i64 {
    let c2i = |c: u8| (c - b'a') as usize;
    let mut next = vec![vec![]; 26];
    for (i, &c) in s.iter().enumerate().rev() {
        next[c2i(c)].push(i);
    }
    let mut ret = usize::MAX;
    let mut base = 0;
    for &c in t {
        let c = c2i(c);
        // lt
        if let Some(&x) = next[0..c].iter().filter_map(|i| i.last()).min() {
            ret = ret.min(base + dist(&next, x) - 1);
            if ret == 0 {
                break;
            }
        }
        // eq
        if let Some(x) = next[c].pop() {
            base += dist(&next, x);
        } else {
            break;
        }
    }
    if ret == usize::MAX {
        -1
    } else {
        ret as i64
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let s = read_line();
        let t = read_line();
        println!("{}", gao(s.trim().as_bytes(), t.trim().as_bytes()))
    }
}

// 147127653	Feb/20/2022 17:47UTC-8	watashi	1616E - Lexicographically Small Enough	Rust 2021	Accepted	108 ms	3000 KB
