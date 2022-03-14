use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n: usize = read_line().trim().parse().unwrap();
        let mut m = n - 1;
        while m.count_ones() > 1 {
            m -= 1;
        }
        let ans = (0..m)
            .rev()
            .chain(m..n)
            .map(|i| i.to_string())
            .collect::<Vec<_>>();
        println!("{}", ans.join(" "));
    }
}

// 149574592	Mar/13/2022 20:59UTC-7	watashi	1632B - Roof Construction	Rust 2021	Accepted	93 ms	9100 KB
