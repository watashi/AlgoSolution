use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn query(a: usize, b: usize, c: usize) -> i32 {
    println!("? {} {} {}", a, b, c);
    read_line().trim().parse().unwrap()
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let n = read_line().trim().parse().unwrap();
        let mut qs = vec![];
        for i in 1..=4 {
            if let [a, b, c] = (1..=4).filter(|&j| i != j).collect::<Vec<_>>()[..] {
                qs.push((query(a, b, c), i));
            }
        }
        qs.sort_unstable();

        let mut todo = 5;
        let mut maxd = qs.last().unwrap().0;
        let mut triples = vec![]; // (boundary1, preferred_boundary2, fallback_boundary2)
        if maxd == 0 {
            // [a, a, a, a]
            while maxd == 0 {
                maxd = query(1, 2, todo);
                todo += 1;
            }
            triples.push((todo - 1, 1, 2));
        } else if qs[0].0 == maxd {
            // [a, a, b, b]
            loop {
                let q1 = query(1, 3, todo);
                let q2 = query(2, 3, todo);
                todo += 1;
                if maxd < q1 || maxd < q2 {
                    maxd = q1.max(q2);
                    if q1 >= q2 {
                        triples.push((todo - 1, 1, 3));
                    } else {
                        triples.push((todo - 1, 2, 3));
                    }
                    break;
                }
            }
        } else if qs[1].0 == maxd {
            // [a, a, b, c] or [a, a, a, b]
            triples.push((qs[0].1, qs[1].1, qs[2].1));
        } else {
            // [a, b, c, d]
            triples.push((qs[0].1, qs[1].1, qs[2].1));
        }

        while todo <= n {
            let (a, b, c) = triples[0];
            let q1 = query(a, b, todo);
            let q2 = query(a, c, todo);
            if q1 > q2 {
                if maxd < q1 {
                    maxd = q1;
                    triples.clear();
                    triples.push((todo, b, a));
                } else if maxd == q1 {
                    triples.push((a, b, todo));
                }
            } else if q2 > q1 {
                if maxd < q2 {
                    maxd = q2;
                    triples.clear();
                    triples.push((todo, c, a));
                } else if maxd == q2 {
                    triples.push((a, c, todo));
                }
            } else if maxd <= q1 {
                maxd = q1;
                triples.clear();
                triples.push((todo, a, b));
                triples.push((todo, a, c));
            }
            todo += 1;
        }

        match triples[..] {
            [(a, b, _)] => println!("! {} {}", a, b),
            _ => {
                let mut hs = collections::HashMap::<usize, usize>::new();
                for (a, b, c) in triples {
                    for i in [a, b, c] {
                        *hs.entry(i).or_default() += 1;
                    }
                }
                let maxc = *hs.values().max().unwrap();
                let mut ans = vec![];
                for (k, v) in hs {
                    if v == maxc {
                        ans.push(k);
                    }
                }
                if ans.len() < 2 {
                    ans.push(1);
                }
                println!("! {} {}", ans[0], ans[1]);
            }
        }
    }
}

// 150316210	Mar/20/2022 19:54UTC-7	watashi	1634D - Finding Zero	Rust 2021	Accepted	124 ms	500 KB
