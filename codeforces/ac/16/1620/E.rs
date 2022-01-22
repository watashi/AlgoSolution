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
    let n = read_line().trim().parse().unwrap();
    let ops = (0..n).map(|_| read_vec::<i64>()).collect::<Vec<_>>();
    let mut ans = vec![];
    let mut m = collections::HashMap::new();
    for op in ops.iter().rev() {
        match op[..] {
            [1, x] => {
                ans.push(m.get(&x).unwrap_or(&x).to_string());
            }
            [2, x, y] => {
                let &y = m.get(&y).unwrap_or(&y);
                m.insert(x, y);
            }
            _ => {}
        }
    }
    ans.reverse();
    println!("{}", ans[..].join(" "));
}

// 140846822	Dec/27/2021 15:53UTC-8	watashi	1620E - Replace the Numbers	Rust 2021	Happy New Year!	249 ms	63000 KB
