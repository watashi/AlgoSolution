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

fn main() -> Result<()> {
    let mut stdout = BufWriter::new(stdout());
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let nmk = read_vec::<i64>();
        if let [n, m, k] = nmk[..] {
            let (q, r) = (n / m, n % m);
            let mut s = 0;
            writeln!(stdout, "")?;
            for _ in 0..k {
                for i in 0..m {
                    if i < r {
                        write!(stdout, "{}", q + 1)?;
                        write!(stdout, " {}", (s + i) % n + 1)?;
                    } else {
                        write!(stdout, "{}", q)?;
                    }
                    for j in 0..q {
                        write!(stdout, " {}", (s + r + i + j * m) % n + 1)?;
                    }
                    writeln!(stdout, "")?;
                }
                s = (s + r) % n;
            }
        }
    }
    Ok(())
}

// 140533922	Dec/24/2021 18:44UTC-8	watashi	1619F - Let's Play the Hat?	Rust 2021	Happy New Year!	15 ms	0 KB
