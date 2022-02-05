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

fn dfs(v: usize, e: &Vec<Vec<usize>>, p: &mut Vec<usize>, s: &mut Vec<Vec<i64>>) {
    let mut ss = 0;
    let mut sv = vec![ss];
    for &w in &e[v] {
        p[w] = v;
        dfs(w, e, p, s);
        let n = s[w].len() as i64 - 1;
        ss += s[w].last().unwrap() + n * (n - 1) / 2 + 1;
        sv.push(ss);
    }
    s[v] = sv;
}

fn main() {
    let (n, m) = {
        let nm = read_vec::<usize>();
        (nm[0], nm[1])
    };

    let mut e = vec![vec![]; n + 1];
    let s = read_line();
    let mut v = vec![];
    for (i, c) in (1..=n).zip(s.trim().chars()) {
        if c == '(' {
            v.push(i);
        } else if let Some(j) = v.pop() {
            let &k = v.last().unwrap_or(&0);
            e[k].push(j);
        }
    }
    for j in v {
        let ej = mem::replace(&mut e[j], vec![]);
        e[0].extend(ej);
    }

    let mut p = vec![0; n + 1];
    let mut s = vec![vec![]; n + 1];
    dfs(0, &e, &mut p, &mut s);

    let mut ans = vec![];
    for _ in 0..m {
        match &read_vec::<usize>()[..] {
            &[2, l, r] => {
                let p = p[l];
                // println!("p={}; {:?} {:?}", p, e[p], s[p]);
                let l = e[p].binary_search(&l).unwrap();
                let r = e[p].binary_search(&r).err().unwrap();
                let d = (r - l) as i64;
                ans.push((s[p][r] - s[p][l] + d * (d - 1) / 2).to_string());
            }
            _ => {}
        }
    }
    println!("{}", ans[..].join("\n"));
}

// 143817233	Jan/23/2022 11:53UTC-8	watashi	1625E1 - Cats on the Upgrade (easy version)	Rust 2021	Accepted	280 ms	56700 KB
