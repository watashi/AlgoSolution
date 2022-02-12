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

fn join<T>(a: impl IntoIterator<Item = T>, b: &str) -> String
where
    T: string::ToString,
{
    a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(b)
}

fn dfs(
    e: &Vec<Vec<usize>>,
    c: &Vec<u32>,
    s: u32,
    v: usize,
    p: usize,
    ee: &mut Vec<Vec<usize>>,
) -> u32 {
    let mut sv = c[v];
    for &w in &e[v] {
        if w != p {
            let sw = dfs(e, c, s, w, v, ee);
            if c[v] == 0 && c[w] == 0 && sw >= 2 {
                ee[w].push(v);
            }
            sv += sw;
        }
    }
    if v != p && c[v] == 0 && c[p] == 0 && s - sv >= 2 {
        ee[p].push(v);
    }
    sv
}

fn main() {
    let n = read_line().trim().parse().unwrap();
    let c = read_vec::<u32>();
    let mut e = vec![vec![]; n];
    for _ in 1..n {
        if let [u, v] = read_vec::<usize>()[..] {
            e[u - 1].push(v - 1);
            e[v - 1].push(u - 1);
        }
    }

    let mut ee = vec![vec![]; n];
    dfs(&e, &c, c.iter().sum::<u32>(), 0, 0, &mut ee);

    let mut ans = c.clone();
    let mut q = vec![];
    for i in 0..n {
        if c[i] == 1 {
            for &j in &e[i] {
                if ans[j] == 0 {
                    ans[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    while let Some(i) = q.pop() {
        for &j in &ee[i] {
            if ans[j] == 0 {
                ans[j] = 1;
                q.push(j);
            }
        }
    }
    println!("{}", join(ans, " "));
}

// 146020213	Feb/11/2022 22:25UTC-8	watashi	1626E - Black and White Tree	Rust 2021	Accepted	327 ms	58200 KB
