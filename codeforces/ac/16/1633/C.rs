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
    const YES: [&str; 2] = ["NO", "YES"];
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let [hc, dc]: [i64; 2] = read_vec::<i64>().try_into().unwrap();
        let [hm, dm]: [i64; 2] = read_vec::<i64>().try_into().unwrap();
        let [k, w, a]: [i64; 3] = read_vec::<i64>().try_into().unwrap();
        let yes =
            (0..=k).any(|x| ((hc + a * x + dm - 1) / dm).saturating_mul(dc + w * (k - x)) >= hm);
        println!("{}", YES[yes as usize]);
    }
}

// 150179532	Mar/19/2022 15:34UTC-7	watashi	1633C - Kill the Monster	Rust 2021	Accepted	405 ms	0 KB
