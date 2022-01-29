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
        let nk = read_vec::<usize>();
        let (n, k) = (nk[0], nk[1]);
        let mut c = [0; 26];
        for i in read_line().trim().chars() {
            c[i as usize - b'a' as usize] += 1;
        }
        let mut ans = c.into_iter().map(|i| i / 2).sum::<usize>() / k * 2;
        if ans * k + k <= n {
            ans += 1;
        }
        println!("{}", ans);
    }
}

// 143810688	Jan/23/2022 09:55UTC-8	watashi	1624D - Palindromes Coloring	Rust 2021	Accepted	77 ms	700 KB
