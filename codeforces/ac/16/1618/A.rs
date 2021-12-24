fn readline() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re: i32 = readline().trim().parse().unwrap();
    for _ri in 0..re {
        let v: Vec<i32> = readline()
            .trim()
            .split_whitespace()
            .map(|i| i.parse().unwrap())
            .collect();
        let a = v[0];
        let b = v[1];
        let c = if v[2] == a + b { v[3] } else { v[2] };
        println!("{} {} {}", a, b, c);
    }
}

// 140395783	Dec/23/2021 16:48UTC-8	watashi	1618A - Polycarp and Sums of Subsequences	Rust 2021	Accepted	62 ms	0 KB
