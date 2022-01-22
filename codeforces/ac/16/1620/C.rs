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
        let nkx = read_vec::<usize>();
        let s = read_line();
        if let [k, mut x] = nkx[1..3] {
            x -= 1;
            let mut ans = vec![];
            for i in s.trim().split('a').rev() {
                let m = i.len() * k + 1;
                ans.push(String::from_utf8(vec![b'b'; x % m]).unwrap());
                x /= m;
            }
            ans.reverse();
            println!("{}", ans[..].join("a"));
        }
    }
}

// 140845928	Dec/27/2021 15:08UTC-8	watashi	1620C - BA-String	Rust 2021	Happy New Year!	15 ms	7800 KB
