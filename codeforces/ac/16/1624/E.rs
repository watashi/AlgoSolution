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
        let nm = read_vec::<usize>();
        let (n, m) = (nm[0], nm[1]);
        let mut hm2 = collections::HashMap::new();
        let mut hm3 = collections::HashMap::new();
        for i in 1..=n {
            let s = read_line();
            let mut x = 0;
            for (j, c) in (1..=m).zip(s.chars()) {
                x = (x * 10 + c as i32 - 'a' as i32) % 1000;
                if j > 1 {
                    hm2.insert(x % 100, (j - 1, j, i));
                    if j > 2 {
                        hm3.insert(x, (j - 2, j, i));
                    }
                }
            }
        }

        let mut dp = vec![None; m + 1];
        dp[0] = Some(&(0, 0, 0));
        let s = read_line();
        let mut x = 0;
        for (j, c) in (1..=m).zip(s.chars()) {
            x = (x * 10 + c as i32 - 'a' as i32) % 1000;
            if j > 1 && dp[j - 2].is_some() {
                dp[j] = hm2.get(&(x % 100));
            }
            if !dp[j].is_some() && j > 2 && dp[j - 3].is_some() {
                dp[j] = hm3.get(&x);
            }
        }

        if dp[m].is_some() {
            let mut ans = vec![];
            let mut j = m;
            dp[0] = None;
            while let Some(&(l, r, i)) = dp[j] {
                ans.push(format!("{} {} {}", l, r, i));
                j -= r - l + 1;
            }
            ans.reverse();
            println!("{}\n{}", ans.len(), ans[..].join("\n"));
        } else {
            println!("-1");
        }
    }
}

// 143809932	Jan/23/2022 09:44UTC-8	watashi	1624E - Masha-forgetful	Rust 2021	Accepted	202 ms	1400 KB
