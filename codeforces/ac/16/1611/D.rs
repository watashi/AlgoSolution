use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec() -> Vec<usize> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let b = read_vec();
        let p = read_vec();
        let mut d = vec![0; n];
        for (i, &j) in p.iter().enumerate() {
            d[j - 1] = i as i32;
        }
        let mut w = vec![0; n];
        for (i, j) in b.iter().enumerate() {
            w[i] = d[i] - d[j - 1];
        }
        if w.iter().all(|&i| i >= 0) {
            println!(
                "{}",
                w.iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(" ")
            );
        } else {
            println!("-1");
        }
    }
}

// 141380821	Jan/02/2022 01:03UTC-8	watashi	1611D - Weights Assignment For Tree Edges	Rust 2021	Happy New Year!	62 ms	14800 KB
