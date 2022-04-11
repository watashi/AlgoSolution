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

fn fibfy(d: &Vec<i64>, m: i64) -> Vec<i64> {
    let (mut a, mut b) = (0, 0);
    let mut ret = Vec::with_capacity(d.len());
    for &i in d {
        let c = (a + b + i).rem_euclid(m);
        a = b;
        b = c;
        ret.push(c);
    }
    ret
}

fn add(a: &mut i64, b: i64, m: i64, nz: &mut usize) {
    if *a == 0 {
        *nz += 1;
    }
    *a = (*a + b).rem_euclid(m);
    if *a == 0 {
        *nz -= 1;
    }
}

fn main() {
    let [n, q, m]: [usize; 3] = read_vec::<usize>().try_into().unwrap();
    let a = read_vec::<i64>();
    let b = read_vec::<i64>();

    let m = m as i64;
    let mut fib = vec![0; n];
    fib[0] = 1i64;
    fib = fibfy(&fib, m);

    let mut d = vec![0; n];
    for (i, (ai, bi)) in a.into_iter().zip(b).enumerate() {
        d[i] = (ai - bi).rem_euclid(m);
    }
    for i in (2..n).rev() {
        d[i] = (d[i] - d[i - 1] - d[i - 2]).rem_euclid(m);
    }
    if n > 1 {
        d[1] -= d[0];
    }
    let mut nz = d.iter().filter(|&&i| i != 0).count();
    // println!("{:?}", fibfy(&d, m));

    let mut ans = vec![];
    for _ in 0..q {
        let s = read_vec::<String>();
        let f = if s[0] == "A" { 1 } else { -1 };
        let l = s[1].parse::<usize>().unwrap() - 1;
        let r = s[2].parse::<usize>().unwrap();
        add(&mut d[l], f, m, &mut nz);
        if r < n {
            add(&mut d[r], -f * fib[r - l], m, &mut nz);
            if r + 1 < n {
                add(&mut d[r + 1], -f * fib[r - l - 1], m, &mut nz);
            }
        }
        // println!("{:?}", fibfy(&d, m));
        ans.push(if nz == 0 { "YES" } else { "NO" });
    }
    println!("{}", ans.join("\n"));
}

// 150190111	Mar/19/2022 21:31UTC-7	watashi	1634F - Fibonacci Additions	Rust 2021	Accepted	187 ms	18300 KB
