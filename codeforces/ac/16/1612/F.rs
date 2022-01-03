use std::{cmp::*, collections::*, *};

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
    let nm = read_vec::<i32>();
    let (n, m) = (nm[0], nm[1]);
    let q = read_line().trim().parse().unwrap();
    let mut hs = HashSet::new();
    for _ in 0..q {
        let ab = read_vec::<i32>();
        hs.insert((ab[0], ab[1]));
    }

    let mut ans = 0;
    let mut from = vec![(1, 1)];
    while from.last() != Some(&(n, m)) {
        let mut to = vec![];
        for (i, j) in from {
            let k = i + j + hs.contains(&(i, j)) as i32;
            to.push((min(n, k), j));
            to.push((i, min(m, k)));
        }
        from = vec![];
        to.sort_unstable();
        for (i, j) in to {
            while from.len() > 0 && from.last().unwrap().1 <= j {
                from.pop();
            }
            from.push((i, j));
        }
        ans += 1;
        // eprintln!("{}: {:?}", from.len(), from);
    }
    println!("{}", ans);
}

// 141444021	Jan/02/2022 17:41UTC-8	watashi	1612F - Armor and Weapons	Rust 2021	Happy New Year!	93 ms	5100 KB
