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

fn join<T>(a: impl IntoIterator<Item = T>, b: &str) -> String
where
    T: string::ToString,
{
    a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(b)
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [n, m] = read_vec::<i32>()[..] {
            let mut d = (1..=n)
                .flat_map(|i| {
                    let d = (i - 1).max(n - i);
                    (1..=m).map(move |j: i32| d + (j - 1).max(m - j))
                })
                .collect::<Vec<_>>();
            d.sort_unstable();
            println!("{}", join(d, " "));
        }
    }
}

// 145604490	Feb/07/2022 20:48UTC-8	watashi	1627B - Not Sitting	Rust 2021	Accepted	93 ms	4700 KB
