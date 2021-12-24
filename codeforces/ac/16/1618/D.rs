fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .trim()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let re: i32 = read_line().trim().parse().unwrap();
    for _ri in 0..re {
        let nk = read_vec::<usize>();
        let (n, k) = (nk[0], nk[1]);
        let m = n - k - k;

        let mut a = read_vec::<i32>();
        a.sort();
        let mut s: i32 = a[..m].iter().sum();
        let (mut pre, mut cnt) = (-1, 0);
        for &i in a[m..].iter() {
            if i != pre {
                pre = i;
                cnt = 1;
            } else {
                cnt += 1;
                if cnt > k {
                    s += 1;
                }
            }
        }
        println!("{}", s);
    }
}

// 140397806	Dec/23/2021 18:19UTC-8	watashi	1618D - Array and Operations	Rust 2021	Accepted	30 ms	100 KB
