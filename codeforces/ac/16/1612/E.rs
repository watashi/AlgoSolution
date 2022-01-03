use std::{collections::*, *};

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

fn lt(a: (u64, usize), b: (u64, usize)) -> bool {
    a.0 * (b.1 as u64) < b.0 * a.1 as u64
}

fn main() {
    let n = read_line().trim().parse().unwrap();
    let mut m = HashMap::<_, Vec<_>>::new();
    let mut maxk = 0;
    for _ in 0..n {
        let a = read_vec::<u64>();
        maxk = cmp::max(maxk, a[1]);
        m.entry(a[0]).or_default().push(a[1]);
    }
    let maxk = maxk as usize;

    let mut best = (0, 1);
    let mut ans = vec![];
    for t in 1..=cmp::min(maxk, m.len()) {
        let mut s = vec![];
        for (&i, j) in &m {
            s.push((j.iter().map(|&k| cmp::min(k, t as u64)).sum::<u64>(), i));
        }
        s.sort_unstable_by(|i, j| j.0.cmp(&i.0));
        if t < maxk {
            let temp = (s[0..t].iter().map(|i| i.0).sum::<u64>(), t);
            if lt(best, temp) {
                best = temp;
                ans = s[0..t].iter().map(|i| i.1).collect();
            }
        } else {
            let mut sum = 0;
            let mut anslen = 0;
            for i in 1..=s.len() {
                sum += s[i - 1].0;
                let temp = (sum, i);
                if i >= maxk && lt(best, temp) {
                    best = temp;
                    anslen = i;
                }
            }
            if anslen > 0 {
                ans = s[0..anslen].iter().map(|i| i.1).collect();
            }
        }
    }
    println!("{}\n{}", ans.len(), join(ans, " "));
}

// 141467648	Jan/03/2022 00:57UTC-8	watashi	1612E - Messages	Rust 2021	Happy New Year!	311 ms	25600 KB
