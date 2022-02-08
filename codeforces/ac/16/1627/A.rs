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
        let [n, _, r, c]: [usize; 4] = read_vec::<usize>().try_into().unwrap();
        let (r, c) = (r - 1, c - 1);
        let a = (0..n).map(|_| read_line()).collect::<Vec<_>>();
        let ans = if a[r].as_bytes()[c] == b'B' {
            0
        } else if a[r].find(|c| c == 'B').is_some() || (0..n).any(|i| a[i].as_bytes()[c] == b'B') {
            1
        } else if a.iter().any(|i| i.find(|c| c == 'B').is_some()) {
            2
        } else {
            -1
        };
        println!("{}", ans);
    }
}

// 145605133	Feb/07/2022 20:59UTC-8	watashi	1627A - Not Shading	Rust 2021	Accepted	15 ms	0 KB
