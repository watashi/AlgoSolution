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
        let mut c = collections::BTreeMap::<i32, i32>::new();
        for i in read_vec::<i32>() {
            *c.entry(i).or_default() += 1;
        }
        let mut ss = 0;
        let mut s = vec![ss];
        for &i in c.values() {
            ss += i;
            s.push(ss);
        }

        let mut ans = i32::MAX;
        let mut x = 1;
        loop {
            let ix = s.binary_search(&x).map_or_else(|i| i - 1, |i| i);
            let mut y = 1;
            loop {
                let iy = s.binary_search(&(s[ix] + y)).map_or_else(|i| i - 1, |i| i);
                let mut z = 1;
                while z < ss - s[iy] {
                    z *= 2;
                }
                ans = ans.min(x + y + z);
                if s[ix] + y >= ss {
                    break;
                }
                y *= 2;
            }
            if x >= ss {
                break;
            }
            x *= 2;
        }
        println!("{}", ans - ss);
    }
}

// 145492880	Feb/06/2022 19:11UTC-8	watashi	1626D - Martial Arts Tournament	Rust 2021	Accepted	140 ms	6400 KB
