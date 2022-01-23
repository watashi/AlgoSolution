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

const DIRS: [(i32, i32); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if let [n, m] = read_vec::<i32>()[..] {
            let mut s: Vec<Vec<_>> = (0..n).map(|_| read_line().chars().collect()).collect();
            let mut d = vec![vec![0; m as usize]; n as usize];
            let (mut x0, mut y0) = (0, 0);
            for x in 0..n {
                for y in 0..m {
                    match s[x as usize][y as usize] {
                        'L' => {
                            x0 = x;
                            y0 = y;
                        }
                        '.' => {}
                        _ => continue,
                    }
                    for (dx, dy) in DIRS {
                        let (xx, yy) = (x + dx, y + dy);
                        if (0..n).contains(&xx)
                            && (0..m).contains(&yy)
                            && s[xx as usize][yy as usize] != '#'
                        {
                            d[x as usize][y as usize] += 1;
                        }
                    }
                }
            }

            let mut q = vec![(x0, y0)];
            d[x0 as usize][y0 as usize] = 0;
            while let Some((x, y)) = q.pop() {
                for (dx, dy) in DIRS {
                    let (xx, yy) = (x + dx, y + dy);
                    if (0..n).contains(&xx) && (0..m).contains(&yy) {
                        let ss = &mut s[xx as usize][yy as usize];
                        if *ss == '.' {
                            let dd = &mut d[xx as usize][yy as usize];
                            if *dd <= 2 {
                                *ss = '+';
                                q.push((xx, yy));
                            } else {
                                *dd -= 1;
                            }
                        }
                    }
                }
            }

            let s: Vec<String> = s.into_iter().map(|i| i.into_iter().collect()).collect();
            print!("{}", s[..].join(""));
        }
    }
}

// 143497156	Jan/21/2022 00:35UTC-8	watashi	1613E - Crazy Robot	Rust 2021	Accepted	420 ms	97900 KB
