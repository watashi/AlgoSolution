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

fn check(
    e: &Vec<Vec<usize>>,
    x: &Vec<bool>,
    v: usize,
    p: usize,
    d: usize,
) -> (bool, Option<usize>) {
    if x[v] {
        (true, Some(d))
    } else if v != 0 && e[v].len() == 1 {
        (false, None)
    } else {
        let (fs, gs): (Vec<_>, Vec<_>) = e[v]
            .iter()
            .filter(|&&w| w != p)
            .map(|&w| check(e, x, w, v, d + 1))
            .unzip();
        let g = gs.into_iter().filter_map(|i| i).min();
        let f = fs.into_iter().all(|i| i) || g.map_or(false, |i| i <= 2 * d);
        (f, g)
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let n = read_vec()[0];
        let mut e = vec![Vec::<usize>::new(); n];
        let mut x = vec![false; n];
        for i in read_vec::<usize>() {
            x[i - 1] = true;
        }
        for _ in 1..n {
            if let [u, v] = read_vec::<usize>()[..] {
                let (u, v) = (u - 1, v - 1);
                e[u].push(v);
                e[v].push(u);
            }
        }
        println!(
            "{}",
            if check(&e, &x, 0, 0, 0).0 {
                "NO"
            } else {
                "YES"
            }
        );
    }
}

// 141378406	Jan/02/2022 00:32UTC-8	watashi	1611E1 - Escape The Maze (easy version)	Rust 2021	Happy New Year!	140 ms	58500 KB
