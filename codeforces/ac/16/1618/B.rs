fn readline() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let re: i32 = readline().trim().parse().unwrap();
    for _ri in 0..re {
        let n: usize = readline().trim().parse().unwrap();
        let line = readline();
        let bigrams: Vec<&str> = line.trim().split_whitespace().collect();
        let mut s = Vec::new();
        s.reserve(n);
        s.push(bigrams[0].as_bytes()[0]);
        for i in bigrams {
            if s.last() != Some(&i.as_bytes()[0]) {
                s.push(i.as_bytes()[0]);
            }
            s.push(i.as_bytes()[1]);
        }
        if s.len() < n {
            s.push(b'a');
        }
        println!("{}", String::from_utf8(s).unwrap());
    }
}

// 140396650	Dec/23/2021 17:27UTC-8	watashi	1618B - Missing Bigram	Rust 2021	Accepted	31 ms	200 KB
