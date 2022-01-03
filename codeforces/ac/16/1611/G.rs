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
        if let [n, m] = read_vec::<usize>()[..] {
            let s = (0..n).map(|_| read_line()).collect::<Vec<_>>();
            let mut ans = 0;
            for odd in 0..2 {
                let mut p = Vec::with_capacity(n);
                for i in 0..n {
                    p.push((i + odd) % 2);
                }
                loop {
                    for (i, j) in p.iter_mut().zip(s.iter()) {
                        while *i < m && j.as_bytes()[*i] != b'1' {
                            *i += 2;
                        }
                    }
                    let mut q = vec![0; n];
                    let mut r = m - 1;
                    for i in (0..n).rev() {
                        r += 1;
                        if p[i] < m {
                            r = cmp::min(r, p[i]);
                        }
                        q[i] = r;
                    }
                    // println!("{:?}", p);
                    if r >= m + n - 1 {
                        break;
                    }
                    ans += 1;
                    let mut y = q[0] + 1;
                    for i in 0..n {
                        if y < q[i] {
                            y += 1;
                        } else {
                            y -= 1;
                        }
                        if y == p[i] {
                            p[i] += 2;
                        }
                    }
                }
            }
            println!("{}", ans);
        }
    }
}

// 141355462	Jan/01/2022 16:12UTC-8	watashi	1611G - Robot and Candies	Rust 2021	Happy New Year!	140 ms	27500 KB
