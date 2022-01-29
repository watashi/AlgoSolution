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
        let ok = |x, y| x > 0 && x % y == 0;
        if let [a, b, c] = read_vec::<i64>()[..] {
            println!(
                "{}",
                if ok(2 * b - a, c) || ok(2 * b - c, a) || ok(a + c, 2 * b) {
                    "YES"
                } else {
                    "NO"
                }
            )
        }
    }
}

// 143811251	Jan/23/2022 10:04UTC-8	watashi	1624B - Make AP	Rust 2021	Accepted	139 ms	0 KB
