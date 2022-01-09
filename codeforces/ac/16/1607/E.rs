use std::{cmp::*, *};

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_pair() -> (i32, i32) {
    let p = read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect::<Vec<_>>();
    (p[0], p[1])
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let (n, m) = read_pair();
        let (mut x, mut y) = (0, 0);
        let mut rect = (0, 0, 0, 0);
        for &i in read_line().trim().as_bytes() {
            match i {
                b'U' => x -= 1,
                b'D' => x += 1,
                b'L' => y -= 1,
                b'R' => y += 1,
                _ => {}
            }
            let (x1, y1, x2, y2) = rect;
            let r @ (x1, y1, x2, y2) = (min(x1, x), min(y1, y), max(x2, x), max(y2, y));
            if x2 - x1 >= n || y2 - y1 >= m {
                break;
            } else {
                rect = r;
            }
        }
        println!("{} {}", 1 - rect.0, 1 - rect.1);
    }
}

// 142041797	Jan/08/2022 18:21UTC-8	watashi	1607E - Robot on the Board 1	Rust 2021	Accepted	108 ms	1500 KB
