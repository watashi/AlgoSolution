use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let mut c = vec![0; 26];
        for &b in read_line().trim().as_bytes() {
            c[(b - b'a') as usize] += 1;
        }
        let mut s = vec![String::new(); 3];
        for (i, j) in c.into_iter().enumerate() {
            s[j].push((b'a' + i as u8) as char);
        }
        println!("{}{}{}", s[2], s[1], s[2]);
    }
}

// 145494661	Feb/06/2022 19:47UTC-8	watashi	1626A - Equidistant Letters	Rust 2021	Accepted	15 ms	0 KB
