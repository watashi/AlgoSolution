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
) -> (Option<i64>, Option<usize>) {
    if x[v] {
        (Some(1), Some(d))
    } else if v != 0 && e[v].len() == 1 {
        (None, None)
    } else {
        let (fs, gs): (Vec<_>, Vec<_>) = e[v]
            .iter()
            .filter(|&&w| w != p)
            .map(|&w| check(e, x, w, v, d + 1))
            .unzip();
        let g = gs.into_iter().filter_map(|i| i).min();
        let f = if g.map_or(false, |i| i <= 2 * d) {
            Some(1)
        } else {
            fs.into_iter()
                .collect::<Option<Vec<_>>>()
                .map(|i| i.iter().sum())
        };
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
        println!("{}", check(&e, &x, 0, 0, 0).0.unwrap_or(-1));
    }
}

// 141379280	Jan/02/2022 00:43UTC-8	watashi	1611E2 - Escape The Maze (hard version)	Rust 2021	Happy New Year!	139 ms	62800 KB
