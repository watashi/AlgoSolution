fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn readline() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re: i32 = readline().trim().parse().unwrap();
    for _ri in 0..re {
        readline();
        let a: Vec<i64> = readline()
            .trim()
            .split_whitespace()
            .map(|i| i.parse().unwrap())
            .collect();
        let mut b: [i64; 2] = [0i64, 0i64];
        for i in 0..a.len() {
            let j = i % 2;
            b[j] = gcd(b[j], a[i]);
        }
        for i in 0..a.len() {
            let j = 1 - i % 2;
            if b[j] != 0 && a[i] % b[j] == 0 {
                b[j] = 0;
            }
        }
        println!("{}", if b[0] != 0 { b[0] } else { b[1] });
    }
}

// 140396946	Dec/23/2021 17:40UTC-8	watashi	1618C - Paint the Array	Rust 2021	Accepted	30 ms	200 KB
