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

#[derive(Clone, Copy, Debug)]
pub struct Pair(Result<usize, usize>);

impl Pair {
    pub fn new(a: usize, b: usize) -> Self {
        if b == a + 1 {
            Self(Ok(a))
        } else if a == b + 1 {
            Self(Err(a))
        } else {
            panic!("Pair::new({}, {})", a, b);
        }
    }

    pub fn swap(self) -> Self {
        let (a, b) = self.into();
        return Self::new(b, a);
    }
}

impl From<Pair> for usize {
    fn from(p: Pair) -> Self {
        p.0.map_or_else(|i| i * 2 + 1, |i| i * 2)
    }
}

impl From<Pair> for (usize, usize) {
    fn from(p: Pair) -> Self {
        p.0.map_or_else(|i| (i, i - 1), |i| (i, i + 1))
    }
}

fn reachable<const FORWARD: bool>(
    span: &Vec<(usize, usize)>,
    e: &Vec<Vec<usize>>,
    s: Pair,
) -> Vec<bool> {
    let mut mark = vec![false; span.len() * 2];
    let mut q = vec![];
    mark[usize::from(s)] = true;
    q.push(s);
    // println!("reachable({:?}", s);
    while let Some((a, b)) = q.pop().map(Into::into) {
        // println!("\t({}, {})", a, b);
        let mut todo = vec![];
        if (a < b) == FORWARD {
            for &i in &e[a] {
                let j = if FORWARD { i - 1 } else { i + 1 };
                if i != b && span[b].0 <= j && j <= span[b].1 {
                    todo.push(Pair::new(i, j));
                }
            }
        } else {
            for &j in &e[b] {
                let i = if FORWARD { j - 1 } else { j + 1 };
                if j != a && span[a].0 <= i && i <= span[a].1 {
                    todo.push(Pair::new(i, j));
                }
            }
        }
        for p in todo {
            if !mark[usize::from(p)] {
                mark[usize::from(p)] = true;
                q.push(p);
            }
        }
    }
    mark
}

fn reachable2<const FORWARD: bool>(
    mark: &Vec<bool>,
    rmark: &Vec<bool>,
) -> (Vec<usize>, Vec<usize>, Vec<usize>) {
    let n = mark.len() / 2 - 2;
    let mut ret = (vec![], vec![], vec![]);
    for i in 1..=n {
        let j = if FORWARD { i - 1 } else { i + 1 };
        let p = Pair::new(i, j);
        if j < 1 || j > n || mark[usize::from(p)] {
            match (rmark[usize::from(p)], rmark[usize::from(p.swap())]) {
                (true, true) => ret.0.push(i),
                (true, _) => ret.1.push(i),
                (_, true) => ret.2.push(i),
                _ => {}
            }
        }
    }
    // eprintln!("{:?}", ret);
    ret
}

fn count(lt: &Vec<usize>, gt: &Vec<usize>) -> usize {
    let mut ret = 0;
    let mut j = 0;
    for &i in lt {
        while j < gt.len() && gt[j] <= i {
            j += 1;
        }
        ret += gt.len() - j;
    }
    // println!("count({:?}, {:?}) = {}", lt, gt, ret);
    ret
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let [n, m]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
        let mut forward = vec![vec![]; n + 2];
        let mut backward = vec![vec![]; n + 2];
        for _ in 0..m {
            let [a, b]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
            forward[a].push(b);
            backward[b].push(a);
        }

        let span = {
            let mut span = vec![(0, 0); n + 2];
            span[n + 1] = (n + 1, n + 1);
            let mut left = 1;
            while left <= n {
                let mut right = left;
                while forward[right].contains(&(right + 1)) {
                    right += 1;
                }
                for i in left..=right {
                    span[i] = (left, right);
                }
                left = right + 1;
            }
            span
        };
        if span[1].1 == n {
            println!("{}", n * (n - 1) / 2);
            continue;
        }

        for i in 1..=n {
            forward[0].push(i);
            backward[i].push(0);
            forward[i].push(n + 1);
            backward[n + 1].push(i);
        }
        let (left, right) = (span[1].1, span[n].0);
        let pre = reachable::<true>(&span, &forward, Pair::new(0, 1));
        let rpre = reachable::<false>(&span, &backward, Pair::new(left, left + 1));
        let suf = reachable::<false>(&span, &backward, Pair::new(n + 1, n));
        let rsuf = reachable::<true>(&span, &forward, Pair::new(right, right - 1));
        let mid = reachable::<true>(&span, &forward, Pair::new(left, left + 1));
        let (pp, p1, p2) = reachable2::<true>(&pre, &rpre);
        let (ss, s1, s2) = reachable2::<false>(&suf, &rsuf);

        let mut ans = 0;
        let ok1 = mid[usize::from(Pair::new(right, right - 1))];
        let ok2 = mid[usize::from(Pair::new(right - 1, right))];
        // eprintln!("{} {}", ok1, ok2);
        if ok1 || ok2 {
            ans += count(&pp, &ss);
            ans += count(&pp, &s1);
            ans += count(&pp, &s2);
            ans += count(&p1, &ss);
            ans += count(&p2, &ss);
            if ok1 {
                ans += count(&p1, &s2);
                ans += count(&p2, &s1);
            }
            if ok2 {
                ans += count(&p1, &s1);
                ans += count(&p2, &s2);
            }
        }
        println!("{}", ans);
    }
}

// 144477721	Jan/29/2022 22:45UTC-8	watashi	1616G - Just Add an Edge	Rust 2021	Accepted	451 ms	30500 KB
