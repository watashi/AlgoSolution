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
        read_line();
        let mut a = read_vec::<i32>();
        let mut d = 0;
        for i in 1..a.len() - 1 {
            if a[i] > a[i - 1] && a[i] > a[i + 1] {
                d += 1;
                if i + 2 < a.len() && a[i] <= a[i + 2] {
                    a[i + 1] = a[i + 2];
                } else {
                    a[i + 1] = a[i];
                }
            }
        }
        let a = a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>();
        println!("{}\n{}", d, a.join(" "));
    }
}

// 150671566	Mar/23/2022 23:03UTC-7	watashi	1635B - Avoid Local Maximums	Rust 2021	Accepted	202 ms	12800 KB
