use std::{io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

const abc: &[char] = &['a', 'b', 'c'];

fn is_abc(s: &Vec<char>, mut i: i32) -> bool {
    i -= s[i as usize] as i32 - 'a' as i32;
    i >= 0 && s[i as usize..].starts_with(abc)
}

fn main() {
    let nq = read_vec::<i64>();
    let mut s = read_line().chars().collect::<Vec<_>>();
    let mut ans = s.windows(3).filter(|i| i == &abc).count();
    let mut cout = BufWriter::new(stdout());
    for _ in 0..nq[1] {
        if let [i, c] = &read_vec::<String>()[..] {
            let i = i.parse::<i32>().unwrap() - 1;
            if is_abc(&s, i) {
                ans -= 1;
            }
            s[i as usize] = c.chars().next().unwrap();
            if is_abc(&s, i) {
                ans += 1;
            }
            writeln!(cout, "{}", ans).ok();
        }
    }
}

// 143075971	Jan/16/2022 23:02UTC-8	watashi	1609B - William the Vigilant	Rust 2021	Accepted	46 ms	1000 KB
