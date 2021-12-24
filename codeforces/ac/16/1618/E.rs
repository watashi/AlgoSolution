fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .trim()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re: i32 = read_line().trim().parse().unwrap();
    for _ri in 0..re {
        let n: i64 = read_line().trim().parse().unwrap();
        let b = read_vec::<i64>();
        let m = n * (n + 1) / 2;
        let s: i64 = b.iter().sum();
        let a: Option<Vec<String>> = if s % m != 0 {
            None
        } else {
            let s = s / m;
            (0..b.len())
                .map(|i| {
                    let d = s + b[if i == 0 { b.len() - 1 } else { i - 1 }] - b[i];
                    if d > 0 && d % n == 0 {
                        Some((d / n).to_string())
                    } else {
                        None
                    }
                })
                .collect()
        };
        match a {
            None => println!("NO"),
            Some(a) => {
                println!("YES");
                println!("{}", &a.join(" "));
            }
        };
    }
}

// 140402264	Dec/23/2021 20:21UTC-8	watashi	1618E - Singers' Tour	Rust 2021	Accepted	62 ms	3900 KB
