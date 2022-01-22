fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        if read_line().chars().filter(|&i| i == 'N').count() == 1 {
            println!("NO");
        } else {
            println!("YES");
        }
    }
}

// 140844374	Dec/27/2021 14:02UTC-8	watashi	1620A - Equal or Not Equal	Rust 2021	Happy New Year!	30 ms	0 KB
