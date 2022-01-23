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
        let mut h = read_vec::<i64>()[1];
        let a = read_vec::<i64>();
        let mut c = collections::BTreeMap::new();
        for (&i, &j) in a.iter().skip(1).zip(&a) {
            *c.entry(i - j).or_insert(0) += 1;
        }
        let (mut rate, mut k) = (a.len() as i64, 0);
        for (i, j) in c {
            let d = (h + rate - 1) / rate;
            if k + d <= i {
                k += d;
                h = 0;
                break;
            } else {
                h -= rate * (i - k);
                k = i;
                rate -= j;
            }
        }
        println!("{}", k + h);
    }
}

// 143569404	Jan/21/2022 19:36UTC-8	watashi	1613C - Poisoned Dagger	Rust 2021	Accepted	46 ms	200 KB
