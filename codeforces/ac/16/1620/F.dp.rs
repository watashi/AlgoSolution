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

fn join<T>(a: impl IntoIterator<Item = T>, b: &str) -> String
where
    T: string::ToString,
{
    a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(b)
}

fn solve(a: &Vec<i32>) -> Option<Vec<i32>> {
    let n = a.len();
    let mut dp = [vec![i32::MAX; n], vec![i32::MAX; n]];
    let mut pre = [vec![2; n], vec![2; n]];
    dp[0][0] = i32::MIN;
    dp[1][0] = i32::MIN;
    for i in 1..n {
        for j in 0..2 {
            for k in 0..2 {
                let x = dp[j][i - 1];
                let y = if j == 0 { a[i - 1] } else { -a[i - 1] };
                let z = if k == 0 { a[i] } else { -a[i] };
                let (dpz, prez) = (&mut dp[k][i], &mut pre[k][i]);
                if x < z && y < *dpz {
                    *dpz = y;
                    *prez = j;
                }
                if y < z && x < *dpz {
                    *dpz = x;
                    *prez = j;
                }
            }
        }
    }
    if dp[0][n - 1] == i32::MAX {
        None
    } else {
        let mut j = 0;
        let mut b = Vec::with_capacity(n);
        for i in (0..n).rev() {
            b.push(if j == 0 { a[i] } else { -a[i] });
            j = pre[j][i];
        }
        b.reverse();
        Some(b)
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    let mut ans = vec![];

    for _ in 0..re {
        read_line();
        let a = read_vec::<i32>();
        match solve(&a) {
            Some(b) => {
                ans.push("YES".to_owned());
                ans.push(join(b, " "));
            }
            None => ans.push("NO".to_owned()),
        }
    }
    println!("{}", join(ans, "\n"));
}

// 143376232	Jan/19/2022 19:44UTC-8	watashi	1620F - Bipartite Array	Rust 2021	Accepted	295 ms	50700 KB
