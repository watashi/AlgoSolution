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

fn nonempty(x: &Vec<(u32, usize)>, y: &Vec<(u32, usize)>) -> Option<(usize, usize)> {
    if x.is_empty() || y.is_empty() {
        None
    } else {
        Some((x[0].1, y[0].1))
    }
}

fn pair(b: u32, k: u32, x: &Vec<(u32, usize)>, y: &Vec<(u32, usize)>) -> Option<(usize, usize)> {
    if x.is_empty() || y.is_empty() {
        None
    } else if b == 0 {
        nonempty(x, y)
    } else {
        let b = b - 1;
        let (x0, x1) = x.iter().copied().partition(|i| (i.0 >> b) & 1 == 0);
        let (y0, y1) = y.iter().copied().partition(|i| (i.0 >> b) & 1 == 0);
        if (k >> b) & 1 != 0 {
            pair(b, k, &x0, &y1).or_else(|| pair(b, k, &x1, &y0))
        } else {
            nonempty(&x0, &y1)
                .or_else(|| nonempty(&x1, &y0))
                .or_else(|| pair(b, k, &x0, &y0).or_else(|| pair(b, k, &x1, &y1)))
        }
    }
}

fn main() {
    let k = read_vec::<u32>()[1];
    let a = read_vec::<u32>();
    let mut ans = vec![];
    if k == 0 {
        ans = (1..=a.len()).map(|i| i.to_string()).collect();
    } else {
        let b = u32::BITS - k.leading_zeros() - 1;
        let mut g = collections::HashMap::<_, Vec<_>>::new();
        for (i, j) in (1..).zip(a) {
            g.entry(j >> b).or_default().push((j & ((1 << b) - 1), i));
        }
        for (i, j) in &g {
            if !g.contains_key(&(i ^ 1)) {
                ans.push(j[0].1.to_string());
            } else if i & 1 == 0 {
                match pair(b, k, j, g.get(&(i ^ 1)).unwrap()) {
                    Some((x, y)) => {
                        ans.push(x.to_string());
                        ans.push(y.to_string());
                    }
                    None => {
                        ans.push(j[0].1.to_string());
                    }
                }
            }
        }
    }
    if ans.len() > 1 {
        println!("{}\n{}", ans.len(), ans[..].join(" "));
    } else {
        println!("-1");
    }
}

// 143842341	Jan/23/2022 22:39UTC-8	watashi	1625D - Binary Spiders	Rust 2021	Accepted	217 ms	63600 KB
