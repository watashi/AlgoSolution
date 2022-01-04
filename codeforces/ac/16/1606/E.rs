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
    const M: i64 = 998244353;
    if let [n, m] = read_vec::<usize>()[..] {
        let mut choose = vec![vec![0; n + 1]; n + 1];
        for i in 0..=n {
            choose[i][0] = 1;
            for j in 1..=i {
                choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
                if choose[i][j] >= M {
                    choose[i][j] -= M;
                }
            }
        }

        let mut dp = vec![vec![0; m + 1]; n + 1];
        dp[1][1..].fill(1);
        for i in 1..n {
            let pow = iter::successors(Some(1), |&x| Some(x * i as i64 % M))
                .take(i + 1)
                .collect::<Vec<_>>();
            for j in 1..=m {
                let mut s = 0;
                for k in (i..j).step_by(i) {
                    let jj = j - k;
                    for ii in 1..=i {
                        s += dp[ii][jj] * choose[i + 1][ii] % M * pow[i + 1 - ii] % M;
                    }
                }
                dp[i + 1][j] = s % M;
            }
        }

        let mut ans = 1;
        for _ in 0..n {
            ans = ans * m as i64 % M;
        }
        ans -= dp[n].iter().sum::<i64>();
        println!("{}", ans.rem_euclid(M));
    }
}

// 141592516	Jan/03/2022 16:26UTC-8	watashi	1606E - Arena	Rust 2021	Happy New Year!	234 ms	4300 KB
