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
        let a = read_vec::<i64>();
        let &max = a.iter().max().unwrap();
        let one = a.iter().any(|i| i == &1);
        let [r1, r2] = [1, 2].map(|r| a.iter().any(|i| i % 3 == r));
        let mut s = max / 3;
        if one {
            s += 1;
            if r2 {
                s += 1;
                if max % 3 == 0 {
                    s -= 1;
                }
            }
        } else if r1 && r2 {
            s += 2;
            match max % 3 {
                0 => s -= 1,
                1 => {
                    if a.iter().all(|&i| i != max - 1) {
                        s -= 1;
                    }
                }
                _ => {}
            }
        } else {
            s += r1 as i64;
            s += r2 as i64;
        }
        println!("{}", s);
    }
}

// 140846487	Dec/27/2021 15:36UTC-8	watashi	1620D - Exact Change	Rust 2021	Happy New Year!	15 ms	100 KB
