use std::io::*;

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let mn = read_vec::<usize>();
        let (m, n) = (mn[0], mn[1]);
        let mut v: Vec<(i32, usize, usize)> = vec![];
        for i in 0..m {
            for (j, &k) in read_vec::<i32>().iter().enumerate() {
                v.push((k, i, j));
            }
        }
        v.sort_unstable();
        v.reverse();

        let mut covering: Vec<usize> = vec![n; m];
        let mut covering2 = false;
        let mut covered: Vec<bool> = vec![false; n];
        let mut not_covered = n;
        for (k, i, j) in v {
            if covering[i] == n {
                covering[i] = j;
            } else if covering[i] != j {
                covering2 = true;
            }
            if !covered[j] {
                covered[j] = true;
                not_covered -= 1;
            }
            if covering2 && not_covered == 0 {
                println!("{}", k);
                break;
            }
        }
    }
}

// 140530568	Dec/24/2021 17:00UTC-8	watashi	1619D - New Year's Problem	Rust 2021	Happy New Year!	108 ms	6200 KB
