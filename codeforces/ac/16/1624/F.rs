use std::*;

fn read_i64() -> i64 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse().unwrap()
}

fn main() {
    let n = read_i64();
    let (mut lo, mut hi) = (1, n - 1);
    while lo < hi {
        debug_assert!(lo / n == hi / n);
        let c = n - 1 - (lo % n + hi % n) / 2;
        println!("+ {}", c);
        if read_i64() == lo / n {
            lo += c;
            hi = lo / n * n + (n - 1);
        } else {
            hi += c;
            lo = hi / n * n;
        }
    }
    println!("! {}", lo);
}

// 143808023	Jan/23/2022 09:18UTC-8	watashi	1624F - Interacdive Problem	Rust 2021	Accepted	31 ms	0 KB
