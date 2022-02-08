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

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let mut e = vec![vec![]; n];
        for i in 0..n - 1 {
            if let [mut a, mut b] = read_vec::<usize>()[..] {
                a -= 1;
                b -= 1;
                e[a].push((b, i));
                e[b].push((a, i));
            }
        }

        let ans = match (0..n).filter(|&i| e[i].len() == 1).collect::<Vec<_>>()[..] {
            [mut v, _] => {
                let mut d = vec!["2"; n - 1];
                let mut f = true;
                let mut ev = e[v][0];
                loop {
                    let w = ev.0;
                    if f {
                        d[ev.1] = "5";
                    }
                    if e[w].len() != 2 {
                        break;
                    }
                    f = !f;
                    ev = if e[w][0].0 != v { e[w][0] } else { e[w][1] };
                    v = w;
                }
                d[..].join(" ")
            }
            _ => "-1".to_owned(),
        };
        println!("{}", ans);
    }
}

// 145603498	Feb/07/2022 20:29UTC-8	watashi	1627C - Not Assigning	Rust 2021	Accepted	124 ms	14400 KB
