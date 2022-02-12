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
        let k = read_vec::<i64>();
        let h = read_vec::<i64>();
        let mut a = k
            .into_iter()
            .zip(h)
            .map(|(i, j)| (i - j + 1, i))
            .collect::<Vec<_>>();
        a.sort_unstable();
        let mut ans = 0;
        let mut it = a.into_iter().peekable();
        while let Some((s, mut t)) = it.next() {
            loop {
                match it.peek() {
                    Some(&(i, j)) if i <= t => {
                        t = t.max(j);
                        it.next();
                    }
                    _ => break,
                }
            }
            let n = t - s + 1;
            ans += n * (n + 1) / 2;
        }
        println!("{}", ans);
    }
}

// 145493531	Feb/06/2022 19:26UTC-8	watashi	1626C - Monsters And Spells	Rust 2021	Accepted	109 ms	100 KB
