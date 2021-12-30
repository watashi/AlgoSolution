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

fn pos(n: i32, x: i32) -> i32 {
    if n == 1 {
        x
    } else if (x - 1) / (n - 1) % 2 == 0 {
        (x - 1) % (n - 1) + 1
    } else {
        n - (x - 1) % (n - 1)
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    let mut ans = vec![];
    for _ in 0..re {
        if let [nx, ny, sx, sy, tx, ty] = read_vec()[..] {
            let mut d = 0;
            while pos(nx, sx + d) != tx && pos(ny, sy + d) != ty {
                d += 1;
            }
            ans.push(d.to_string());
        }
    }
    println!("{}", ans[..].join("\n"));
}

// 141137492	Dec/30/2021 00:44UTC-8	watashi	1623A - Robot Cleaner	Rust 2021	Happy New Year!	31 ms	800 KB
