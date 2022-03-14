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
        if let [a, b] = read_vec::<u32>()[..] {
            let mut ans = b - a;
            let mut c = b;
            while c - b < ans {
                let d = if a | c == c {
                    0
                } else {
                    let mut i = u32::BITS - 1;
                    while (a >> i) & 1 != 1 || (c >> i) & 1 != 0 {
                        i -= 1;
                    }
                    while (a >> i) & 1 != 0 || (c >> i) & 1 != 1 {
                        i += 1;
                    }
                    (1 << i) - (a & ((1 << i) - 1))
                };
                ans = ans.min(c - b + d + 1);
                c += 1;
            }
            println!("{}", ans);
        }
    }
}

// 149574286	Mar/13/2022 20:51UTC-7	watashi	1632C - Strange Test	Rust 2021	Accepted	93 ms	0 KB
