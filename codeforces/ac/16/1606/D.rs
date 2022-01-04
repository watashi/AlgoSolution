use std::{cmp::*, *};

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

fn gao(n: usize, m: usize, a: &Vec<Vec<i32>>) -> Vec<(usize, usize)> {
    let mut v = (0..n).collect::<Vec<_>>();
    v.sort_unstable_by_key(|&i| a[i][0]);

    let mut amin = vec![vec![0; m]; n];
    for i in (0..n).rev() {
        for j in 0..m {
            amin[i][j] = a[v[i]][j];
            if i + 1 < n {
                amin[i][j] = min(amin[i][j], amin[i + 1][j]);
            }
            if j > 0 {
                amin[i][j] = min(amin[i][j], amin[i][j - 1]);
            }
        }
    }

    let mut amax = vec![vec![0; m]; n];
    for i in 0..n {
        for j in 0..m {
            amax[i][j] = a[v[i]][j];
            if i > 0 {
                amax[i][j] = max(amax[i][j], amax[i - 1][j]);
            }
            if j > 0 {
                amax[i][j] = max(amax[i][j], amax[i][j - 1]);
            }
        }
    }

    let mut maxk = vec![];
    for i in 1..n {
        let mut k = 0;
        while k < m && amax[i - 1][k] < amin[i][k] {
            k += 1;
        }
        maxk.push((v[i - 1], k));
    }
    maxk.push((v[n - 1], 0));
    maxk
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    'tcase: for _ in 0..re {
        let nm = read_vec::<usize>();
        let (n, m) = (nm[0], nm[1]);
        let mut a = (0..n).map(|_| read_vec::<i32>()).collect::<Vec<_>>();
        let left = gao(n, m, &a);
        for i in &mut a {
            i.reverse();
        }
        let mut right = gao(n, m, &a);
        for i in (1..n).rev() {
            right[i].1 = right[i - 1].1;
        }
        right[0].1 = 0;
        right.reverse();

        let mut conflict = 0;
        let mut color = vec!['R'; n];
        for ((rl, kl), (rr, kr)) in left.into_iter().zip(right) {
            for r in [rl, rr] {
                if color[r] == 'B' {
                    conflict -= 1;
                } else {
                    color[r] = 'B';
                    conflict += 1;
                }
            }
            if conflict == 0 && kl > 0 && kr > 0 && kl + kr >= m {
                println!(
                    "YES\n{} {}",
                    color.iter().collect::<String>(),
                    min(kl, m - 1)
                );
                continue 'tcase;
            }
        }
        println!("NO");
    }
}

// 141594987	Jan/03/2022 18:02UTC-8	watashi	1606D - Red-Blue Matrix	Rust 2021	Happy New Year!	904 ms	92300 KB
