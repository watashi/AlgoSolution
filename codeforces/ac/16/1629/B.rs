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
    let yes = ["NO", "YES"];
    let re = read_line().trim().parse().unwrap();
    let mut ans = vec![];
    for _ in 0..re {
        if let [l, r, k] = read_vec::<usize>()[..] {
            if l == r {
                ans.push(yes[(l > 1) as usize]);
            } else {
                ans.push(yes[(r / 2 - (l - 1) / 2 + k >= r - l + 1) as usize]);
            }
        }
    }
    println!("{}", ans.join("\n"))
}

// 147224741	Feb/21/2022 17:46UTC-8	watashi	1629B - GCD Arrays	Rust 2021	Accepted	46 ms	4100 KB
