use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_pair() -> (usize, usize) {
    let p = read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect::<Vec<_>>();
    (p[0], p[1])
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let (n, m) = read_pair();
        let s = (0..n).map(|_| read_line()).collect::<Vec<_>>();
        let mut d = vec![vec![0; m]; n];
        let mut ans = (0, 0, 0);
        for x0 in 0..n {
            for y0 in 0..m {
                let (mut x, mut y, mut z) = (x0, y0, 0);
                let mut v = vec![];
                loop {
                    if d[x][y] > 0 {
                        z = d[x][y];
                        break;
                    } else if d[x][y] == -1 {
                        let pos = v.iter().position(|i| i == &(x, y)).unwrap();
                        z = (v.len() - pos) as i32;
                        for &(i, j) in &v[pos..] {
                            d[i][j] = z;
                        }
                        v.truncate(pos);
                        break;
                    }
                    d[x][y] = -1;
                    v.push((x, y));
                    match s[x].as_bytes()[y] {
                        b'U' if x > 0 => x -= 1,
                        b'D' if x < n - 1 => x += 1,
                        b'L' if y > 0 => y -= 1,
                        b'R' if y < m - 1 => y += 1,
                        _ => break,
                    }
                }
                for ((i, j), k) in v.into_iter().rev().zip(z + 1..) {
                    d[i][j] = k;
                }
                ans = cmp::max(ans, (d[x0][y0], x0, y0));
            }
        }
        println!("{} {} {}", ans.1 + 1, ans.2 + 1, ans.0);
    }
}

// 142041766	Jan/08/2022 18:20UTC-8	watashi	1607F - Robot on the Board 2	Rust 2021	Accepted	249 ms	121300 KB
