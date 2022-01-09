use std::{cmp::*, io::*};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_pair() -> (i64, i64) {
    let p = read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect::<Vec<_>>();
    (p[0], p[1])
}

fn main() {
    let mut cout = BufWriter::new(stdout());
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        read_line();
        let (n, m) = read_pair();
        let (mut a, mut b, mut c) = (0, 0, 0);
        let x = (0..n)
            .map(|_| {
                let (x, y) = read_pair();
                let i = max(0, m - y);
                let j = max(0, m - x);
                a += x - i;
                b += y - j;
                c += m - i - j;
                (i, j)
            })
            .collect::<Vec<_>>();

        let (a0, b0) = (a, b);
        let d = min((a - b).abs(), c);
        if a > b {
            a -= d;
        } else {
            b -= d;
        }
        c -= d;
        a -= c / 2;
        b -= (c + 1) / 2;
        writeln!(cout, "{}", (a - b).abs()).ok();

        a = a0 - a;
        b = b0 - b;
        for (i, j) in x {
            let k = m - i - j;
            let da = min(a, k);
            let db = k - da;
            a -= da;
            b -= db;
            writeln!(cout, "{} {}", i + da, j + db).ok();
        }
    }
}

// 141694660	Jan/04/2022 20:24UTC-8	watashi	1607G - Banquet Preparations 1	Rust 2021	Happy New Year!	93 ms	3100 KB
