use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let mut a = read_vec::<usize>();
        a.sort_unstable();
        a.reverse();

        let mut unused = vec![];
        let mut cost = 0;
        let mut ans = vec![];
        for i in 0..=n {
            let mut c = 0;
            while a.last() == Some(&i) {
                a.pop();
                c += 1;
            }
            ans.push((cost + c).to_string());
            unused.extend(iter::repeat(i).take(c));
            match unused.pop() {
                Some(x) => cost += i - x,
                None => {
                    ans.resize(n + 1, "-1".to_owned());
                    break;
                }
            }
        }
        println!("{}", ans.join(" "));
    }
}

// 140531955	Dec/24/2021 17:47UTC-8	watashi	1619E - MEX and Increments	Rust 2021	Happy New Year!	93 ms	18800 KB
