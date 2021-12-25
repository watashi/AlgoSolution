use std::io::*;

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn main() {
    let mut stdout = BufWriter::new(stdout());
    let re = read_line().trim().parse().unwrap();
    for _ri in 0..re {
        let line = read_line();
        let mut words = line.split_whitespace().map(|w| w.as_bytes().iter().rev());
        let mut a = words.next().unwrap();
        let mut s = words.next().unwrap();
        let mut b: Vec<u8> = vec![];
        let mut ok = true;
        while ok {
            match (a.next(), s.next()) {
                (Some(da), Some(ds)) => {
                    if da <= ds {
                        b.push(ds - da + b'0')
                    } else if s.next() != Some(&b'1') {
                        ok = false
                    } else {
                        b.push(ds + 10 - da + b'0')
                    }
                }
                (Some(_), None) => ok = false,
                (None, Some(ds)) => b.push(*ds),
                (None, None) => break,
            }
        }
        if ok {
            while b.len() > 1 && b.last() == Some(&b'0') {
                b.pop();
            }
            b.reverse();
            writeln!(stdout, "{}", String::from_utf8(b).unwrap()).ok();
        } else {
            writeln!(stdout, "{}", -1).ok();
        }
    }
}

// 140529892	Dec/24/2021 16:27UTC-8	watashi	1619C - Wrong Addition	Rust 2021	Happy New Year!	0 ms	0 KB
