use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let s = read_line();
        let s = s.trim().as_bytes();
        let c = s.windows(2).take_while(|&i| i[0] >= i[1]).count();
        let x: String = [s[0] as char, s[0] as char].into_iter().collect();
        let y: String = s[0..=c]
            .iter()
            .chain(s[0..=c].iter().rev())
            .map(|&i| i as char)
            .collect();
        println!("{}", x.min(y));
    }
}

// 147140309	Feb/20/2022 21:30UTC-8	watashi	1616B - Mirror in the String	Rust 2021	Accepted	93 ms	600 KB
