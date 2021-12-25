fn read_i64() -> i64 {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line.trim().parse().unwrap()
}

fn bsearch<F: Fn(i64) -> bool>(mut lo: i64, mut hi: i64, f: F) -> i64 {
    while lo < hi {
        let mi = lo + (hi - lo) / 2;
        if f(mi) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    hi
}

fn count(m: i64, n: i64) -> i64 {
    bsearch(1, m + 1, |x| {
        let mut y = m;
        for _ in 0..n {
            y /= x
        }
        y == 0
    }) - 1
}

fn main() {
    let re = read_i64();
    for _ri in 0..re {
        let t = read_i64();
        println!("{}", count(t, 2) + count(t, 3) - count(t, 6));
    }
}

// 140529139	Dec/24/2021 15:47UTC-8	watashi	1619B - Squares and Cubes	Rust 2021	Happy New Year!	15 ms	0 KB
