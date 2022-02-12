use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let mut s = read_line().trim().as_bytes().into_iter().map(|&b| b - b'0').collect::<Vec<_>>();
        if let Some(i) = (1..s.len()).rev().find(|&i| s[i - 1] + s[i] >= 10) {
            let d = s[i - 1] + s[i];
            s[i - 1] = d / 10;
            s[i] = d % 10;
        } else if let Some(i) = (1..s.len()).find(|&i| s[i] > 0) {
            s[i - 1] += s[i];
            s.remove(i);
        } else {
            debug_assert!(s[1] == 0);
            s.remove(1);
        }
        println!("{}", s.into_iter().map(|i| (b'0' + i) as char).collect::<String>());
    }
}

// 145494388	Feb/06/2022 19:42UTC-8	watashi	1626B - Minor Reduction	Rust 2021	Accepted	109 ms	800 KB
