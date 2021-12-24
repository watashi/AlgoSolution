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

fn bitrev(mut x: u64) -> u64 {
    let mut y = 0u64;
    while x > 0 {
        y <<= 1;
        y |= x & 1;
        x >>= 1;
    }
    y
}

fn check(x: u64, mut y: u64) -> bool {
    let mut m = 0;
    while x & ((1 << m) - 1) < x {
        m += 1
    }
    while y > 0 {
        if y & ((1 << m) - 1) == x {
            y >>= m;
            return y & (y + 1) == 0;
        } else if y & 1 == 0 {
            return false;
        } else {
            y >>= 1;
        }
    }
    false
}

fn main() {
    let xy = read_vec::<u64>();
    let (x, y) = (xy[0], xy[1]);
    let mut xx = x;
    while xx & 1 == 0 {
        xx >>= 1
    }
    if x == y
        || check(xx, y)
        || check(bitrev(xx), y)
        || check(x * 2 + 1, y)
        || check(bitrev(x * 2 + 1), y)
    {
        println!("YES")
    } else {
        println!("NO")
    }
}

// 140403333	Dec/23/2021 20:46UTC-8	watashi	1618F - Reverse	Rust 2021	Accepted	15 ms	0 KB
