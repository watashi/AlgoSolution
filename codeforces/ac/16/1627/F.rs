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

fn gao(r: &Vec<Vec<u32>>, c: &Vec<Vec<u32>>) -> u32 {
    let n = r.len();
    let mut d = vec![vec![u32::MAX; n + 1]; n + 1];
    let mut q = collections::BinaryHeap::new();
    q.push((Reverse(0), n / 2, n / 2));
    while let Some((Reverse(z), x, y)) = q.pop() {
        if d[x][y] < z {
            continue;
        } else if x == 0 || y == 0 || x == n || y == n {
            return z;
        } else {
            let mut upd = |i: usize, j: usize, k| {
                if d[i][j] > k {
                    d[i][j] = k;
                    q.push((Reverse(k), i, j));
                }
            };
            upd(x - 1, y, z + r[x - 1][y] + r[n - x][n - y]);
            upd(x, y - 1, z + c[y - 1][x] + c[n - y][n - x]);
            upd(x + 1, y, z + r[x][y] + r[n - 1 - x][n - y]);
            upd(x, y + 1, z + c[y][x] + c[n - 1 - y][n - x]);
        }
    }
    panic!()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let [n, k]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
        let mut r = vec![vec![0; k]; k];
        let mut c = vec![vec![0; k]; k];
        for _ in 0..n {
            if let [r1, c1, r2, c2] = read_vec::<usize>()[..] {
                if r1 == r2 {
                    r[r1 - 1][c1.min(c2)] += 1;
                }
                if c1 == c2 {
                    c[c1 - 1][r1.min(r2)] += 1;
                }
            }
        }
        println!("{}", n as u32 - gao(&r, &c));
    }
}

// 144027926	Jan/25/2022 19:45UTC-8	watashi	1627F - Not Splitting	Rust 2021	Accepted	46 ms	4800 KB
