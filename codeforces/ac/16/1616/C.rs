use std::{collections::*, *};

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

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let a = read_vec::<i32>();
        let mut m = HashMap::<_, HashSet<_>>::new();
        for i in 0..a.len() as i32 {
            for j in 0..i {
                let x = i - j;
                let y = a[i as usize] - a[j as usize];
                let g = gcd(x, y).abs();
                let (dx, dy) = (x / g, y / g);
                let x0 = j % dx;
                let y0 = a[j as usize] - j / dx * dy;
                m.entry((x0, y0, dx, dy)).or_default().insert(i);
            }
        }
        let m = m.values().map(|i| i.len()).max().unwrap_or_default();
        println!("{}", a.len() - m - 1);
    }
}

// 147128946	Feb/20/2022 18:23UTC-8	watashi	1616C - Representative Edges	Rust 2021	Accepted	93 ms	1400 KB
