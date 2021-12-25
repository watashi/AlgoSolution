fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ri in 0..re {
        let s = read_line();
        let b = s.trim().as_bytes();
        let mut yes = b.len() % 2 == 0;
        if yes {
            let d = b.len() / 2;
            for i in 0..d {
                if b[i] != b[i + d] {
                    yes = false;
                    break;
                }
            }
        }
        println!("{}", if yes { "YES" } else { "NO" });
    }
}

// 140528714	Dec/24/2021 15:24UTC-8	watashi	1619A - Square String?	Rust 2021	Happy New Year!	15 ms	0 KB
