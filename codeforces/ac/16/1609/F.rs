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

type Seq = Vec<(usize, i64)>;
type Range = Vec<(usize, usize, usize)>;
type Ranges = Vec<Range>;

// [0, a)
fn query_(w: &Range, a: usize) -> usize {
    let idx = w.binary_search_by(|i| i.0.cmp(&a)).unwrap_or_else(|i| i);
    if idx == 0 {
        0
    } else {
        let (_l, r, s) = w[idx - 1];
        s - (r - cmp::min(a, r))
    }
}

// [l, r)
fn query(w: &Range, l: usize, r: usize) -> usize {
    query_(w, r) - query_(w, l)
}

fn pop(v: &mut Seq, w: &mut Ranges, w2: &Ranges) -> usize {
    if let Some((r, a)) = v.pop() {
        if let Some(&(l, _)) = v.last() {
            let c = a.count_ones() as usize;
            w[c].pop();
            return query(&w2[c], l, r);
        }
    }
    panic!();
}

fn push(v: &mut Seq, w: &mut Ranges, w2: &Ranges, r: usize, a: i64) -> usize {
    let l = v.last().unwrap().0;
    let c = a.count_ones() as usize;
    v.push((r, a));
    let s = w[c].last().map_or(0, |i| i.2);
    w[c].push((l, r, r - l + s));
    query(&w2[c], l, r)
}

fn main() {
    let mut inc: Seq = vec![(0, i64::MIN)];
    let mut dec: Seq = vec![(0, i64::MAX)];
    let mut incs: Ranges = vec![vec![]; 64];
    let mut decs: Ranges = vec![vec![]; 64];
    let (mut ans, mut sum) = (0, 0);
    read_line();
    for (n, a) in (1..).zip(read_vec::<i64>()) {
        while inc.last().unwrap().1 >= a {
            sum -= pop(&mut inc, &mut incs, &decs);
        }
        sum += push(&mut inc, &mut incs, &decs, n, a);
        while dec.last().unwrap().1 <= a {
            sum -= pop(&mut dec, &mut decs, &incs);
        }
        sum += push(&mut dec, &mut decs, &incs, n, a);
        ans += sum as u64;
    }
    println!("{}", ans);
}

// 143043084	Jan/16/2022 15:26UTC-8	watashi	1609F - Interesting Sections	Rust 2021	Accepted	249 ms	61400 KB
