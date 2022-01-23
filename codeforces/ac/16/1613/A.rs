use std::{cmp::Ordering, *};

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

#[derive(Eq, PartialEq)]
struct Scientific {
    x: i64,
    p: i64,
}

impl Scientific {
    fn new(mut x: i64, mut p: i64) -> Self {
        while x % 10 == 0 {
            x /= 10;
            p += 1;
        }
        Self { x: x, p: p }
    }
}

impl Ord for Scientific {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.p < other.p {
            other.cmp(self).reverse()
        } else if self.p - other.p >= 10 {
            Ordering::Greater
        } else {
            (self.x * 10i64.pow((self.p - other.p) as u32)).cmp(&other.x)
        }
    }
}

impl PartialOrd for Scientific {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn read_scientific() -> Scientific {
    let a = read_vec::<i64>();
    Scientific::new(a[0], a[1])
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    let mut ans = vec![];
    for _ in 0..re {
        let a = read_scientific();
        let b = read_scientific();
        ans.push(match a.cmp(&b) {
            Ordering::Greater => ">",
            Ordering::Equal => "=",
            Ordering::Less => "<",
        });
    }
    println!("{}", ans[..].join("\n"));
}

// 143571760	Jan/21/2022 20:28UTC-8	watashi	1613A - Long Comparison	Rust 2021	Accepted	31 ms	500 KB
