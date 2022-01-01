fn readln() -> i64 {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line.trim().parse().unwrap()
}

fn main() {
    let re = readln();
    let mut ans = vec![];
    for _ in 0..re {
        let n = readln();
        let m = n / 2;
        let x = match n % 4 {
            1 => [m + 1, m - 1, 1],
            3 => [m + 2, m - 2, 1],
            _ => [m, m - 1, 1],
        };
        ans.push(x.map(|i| i.to_string()).join(" "));
    }
    println!("{}", ans[..].join("\n"));
}

// 140877997	Dec/28/2021 01:29UTC-8	watashi	1617B - GCD Problem	Rust 2021	Happy New Year!	62 ms	8400 KB
