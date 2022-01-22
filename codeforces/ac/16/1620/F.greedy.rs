use std::*;

pub struct RMQ<T> {
    index: Vec<Vec<usize>>,
    value: Vec<T>,
}

impl<T: Ord> RMQ<T> {
    fn min(v: &Vec<T>, i: usize, j: usize) -> usize {
        if v[i].cmp(&v[j]).is_le() {
            i
        } else {
            j
        }
    }

    pub fn new(value: Vec<T>) -> Self {
        let mut index = vec![];
        let mut prev = (0..value.len()).collect::<Vec<_>>();
        let mut step = 1;
        while !prev.is_empty() {
            let next = prev
                .iter()
                .zip(prev.iter().skip(step))
                .map(|(&i, &j)| Self::min(&value, i, j))
                .collect();
            index.push(prev);
            prev = next;
            step *= 2;
        }
        RMQ {
            index: index,
            value: value,
        }
    }

    pub fn index(&self, start: usize, end: usize) -> usize {
        let n = (usize::BITS - (end - start).leading_zeros() - 1) as usize;
        Self::min(
            &self.value,
            self.index[n][start],
            self.index[n][end - (1 << n)],
        )
    }

    pub fn value(&self, start: usize, end: usize) -> &T {
        &self.value[self.index(start, end)]
    }
}

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

fn lds_lds<'a>(v: impl IntoIterator<Item = &'a i32>) -> Option<(Vec<i32>, Vec<i32>)> {
    let (mut a, mut b) = (vec![], vec![]);
    for &i in v {
        if a.last().map_or(true, |&j| i < j) {
            a.push(i);
        } else if b.last().map_or(true, |&j| i < j) {
            b.push(i);
        } else {
            return None;
        }
    }
    Some((a, b))
}

fn vshape_vshape(a: &Vec<i32>) -> Option<(Vec<bool>, [Vec<i32>; 4])> {
    let pos1 = a.iter().position(|i| i == &1).unwrap();
    let prefix = lds_lds(&a[0..=pos1]);
    if prefix.is_none() {
        return None;
    }
    let (lds1, mut lds2) = prefix.unwrap();

    let n = a.len();
    let mut dec = (0..n).collect::<Vec<_>>();
    for i in 1..n {
        if a[i] < a[i - 1] {
            dec[i] = dec[i - 1];
        }
    }
    let mut inc = (0..n).collect::<Vec<_>>();
    for i in (1..n).rev() {
        if a[i - 1] < a[i] {
            inc[i - 1] = inc[i];
        }
    }

    let rmq = RMQ::new(a.clone());
    let (mut start, mut end) = (pos1 + 1, pos1 + 1);
    let mut lis1 = vec![];
    while start < n {
        end = rmq.index(start, n);
        if end == start || (dec[end] <= start && lds2.last().map_or(true, |&i| i > a[start])) {
            lis1.push(a[end]);
            lds2.extend(&a[start..end]);
            end += 1;
            start = end;
        } else {
            break;
        }
    }

    let suffix = lds_lds(a[end..].iter().rev());
    if suffix.is_none() {
        return None;
    }
    let (rlis2, mut rlis1) = suffix.unwrap();

    let mut rlds2 = vec![];
    while start < end {
        let m = rmq.index(start, end);
        // eprintln!("{:?} => {}", &a[start..end], a[m]);
        if rlis1.last().map_or(true, |&i| i > a[m])
            && (m == start || (dec[m] <= start && lds2.last().map_or(true, |&i| i > a[start])))
        {
            lis1.push(a[m]);
            lds2.extend(&a[start..m]);
            start = m + 1;
        } else if lds2.last().map_or(true, |&i| i > a[m])
            && (m == end - 1
                || (inc[m] >= end - 1 && rlis1.last().map_or(true, |&i| i > a[end - 1])))
        {
            rlds2.push(a[m]);
            rlis1.extend(a[m + 1..end].iter().rev());
            end = m;
        } else {
            return None;
        }
    }

    lds2.extend(rlds2.into_iter().rev());
    lis1.extend(rlis1.into_iter().rev());
    let lis2 = Vec::from_iter(rlis2.into_iter().rev());
    let mut b = vec![false; n + 1];
    for &i in [&lds1, &lds2].into_iter().flatten() {
        b[i as usize] = true;
    }
    debug_assert!(lds1.last() == Some(&1));
    Some((b, [lds1, lis1, lds2, lis2]))
}

fn solve(mut a: Vec<i32>) -> Option<(Vec<bool>, [Vec<i32>; 4])> {
    match vshape_vshape(&a) {
        None => {
            a.reverse();
            vshape_vshape(&a).map(|(mut b, [mut lds1, mut lis1, mut lds2, mut lis2])| {
                for i in b.iter_mut() {
                    *i = !*i;
                }
                lds1.reverse();
                lis1.reverse();
                lds2.reverse();
                lis2.reverse();
                (b, [lis1, lds1, lis2, lds2])
            })
        }
        some => some,
    }
}

fn main() {
    /*
    use itertools::Itertools;
    let mut cid = 1 + 2 + 6 + 24 + 120;
    for a in (1..=6).permutations(6) {
        cid += 1;
        match solve(a.clone()) {
            Some((b, sol)) => {
                let a = a
                    .into_iter()
                    .map(move |i| (if b[i as usize] { -i } else { i }))
                    .collect::<Vec<_>>();
                let x = lds_lds(a.iter().rev());
                println!("#{}: YES: {:?} => {:?}; {:?}", cid, a, x, sol);
                if x.is_none() {
                    break;
                }
            }
            None => println!("#{}: NO: {:?}", cid, a),
        }
    }
    */

    let re = read_line().trim().parse().unwrap();
    let mut ans = vec![];

    for _ in 0..re {
        read_line();
        let a = read_vec::<i32>();
        match solve(a.clone()) {
            Some((b, _)) => {
                let a = a
                    .into_iter()
                    .map(move |i| (if b[i as usize] { -i } else { i }).to_string())
                    .collect::<Vec<_>>();
                ans.push("YES".to_owned());
                ans.push(a[..].join(" "));
            }
            None => ans.push("NO".to_owned()),
        }
    }
    println!("{}", ans[..].join("\n"));
}

// 143372693	Jan/19/2022 18:29UTC-8	watashi	1620F - Bipartite Array	Rust 2021	Accepted	343 ms	185800 KB
