use std::{collections::*, hash::*, *};

pub struct DisjointSet(Vec<usize>);

impl DisjointSet {
    pub fn new(n: usize) -> Self {
        DisjointSet((0..n).collect())
    }

    pub fn clear(&mut self) {
        self.0.iter_mut().enumerate().for_each(|(i, j)| *j = i);
    }

    pub fn getp(&mut self, x: usize) -> usize {
        if self.0[x] != x {
            self.0[x] = self.getp(self.0[x]);
        }
        self.0[x]
    }

    pub fn setp(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        let x = self.getp(x);
        let y = self.getp(y);
        if x != y {
            let (x, y) = if x < y { (x, y) } else { (y, x) };
            self.0[x] = y;
            Some((x, y))
        } else {
            None
        }
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

fn color(a: i32, b: i32) -> i32 {
    if a == b {
        a
    } else {
        6 - a - b
    }
}

fn assign(i: usize, c: i32, e: &Vec<Vec<(usize, usize)>>, ans: &mut Vec<i32>) -> bool {
    if ans[i] > 0 {
        ans[i] == c
    } else {
        ans[i] = c;
        for &(j, k) in &e[i] {
            if ans[j] > 0 {
                if !assign(k, color(c, ans[j]), e, ans) {
                    return false;
                }
            }
            if ans[k] > 0 {
                if !assign(j, color(c, ans[k]), e, ans) {
                    return false;
                }
            }
        }
        true
    }
}

type Assign = Vec<(usize, i32)>;
type MemoKey = (Vec<usize>, Assign);
type Memo = HashMap<MemoKey, Option<Assign>>;

fn dfs(source: usize, e: &Vec<Vec<(usize, usize)>>, ans: &mut Vec<i32>, memo: &mut Memo) -> bool {
    let mut unknown = BTreeSet::from([source]);
    let mut known = BTreeMap::new();
    let mut q = vec![source];
    while let Some(i) = q.pop() {
        for &(j, k) in &e[i] {
            debug_assert!(ans[j] <= 0 || ans[k] <= 0);
            if ans[j] > 0 {
                known.insert(j, ans[j]);
            } else if unknown.insert(j) {
                q.push(j);
            }
            if ans[k] > 0 {
                known.insert(k, ans[k]);
            } else if unknown.insert(k) {
                q.push(k);
            }
        }
    }
    let key = (unknown.into_iter().collect(), known.into_iter().collect());
    if let Some(value) = memo.get(&key) {
        if let Some(value) = value {
            for &(i, c) in value {
                ans[i] = c;
            }
            true
        } else {
            false
        }
    } else {
        let mut h = hash_map::DefaultHasher::new();
        key.0.hash(&mut h);
        let i = key.0[h.finish() as usize % key.0.len()];
        for c in 1..=3 {
            for &j in &key.0 {
                ans[j] = -1;
            }
            if !assign(i, c, e, ans) {
                continue;
            }
            let mut ok = true;
            for &j in &key.0 {
                if ok && ans[j] <= 0 {
                    ok &= dfs(j, e, ans, memo);
                }
            }
            if ok {
                let value = key.0.iter().map(|&i| (i, ans[i])).collect();
                memo.insert(key, Some(value));
                return true;
            }
        }
        memo.insert(key, None);
        false
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let [n, m]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
        let mut eid = vec![vec![None; n]; n];
        let mut known = vec![];
        for i in 0..m {
            if let [a, b, c] = read_vec::<i32>()[..] {
                let a = a as usize - 1;
                let b = b as usize - 1;
                eid[a][b] = Some(i);
                eid[b][a] = Some(i);
                if c > 0 {
                    known.push((i, c));
                }
            }
        }

        let mut ds = DisjointSet::new(m);
        let mut triples = vec![];
        for i in 0..n {
            for j in 0..i {
                for k in 0..j {
                    if let (Some(a), Some(b), Some(c)) = (eid[i][j], eid[i][k], eid[j][k]) {
                        triples.push((a, b, c));
                        for l in 0..k {
                            if let (Some(aa), Some(bb), Some(cc)) =
                                (eid[l][k], eid[l][j], eid[l][i])
                            {
                                ds.setp(a, aa);
                                ds.setp(b, bb);
                                ds.setp(c, cc);
                            }
                        }
                    }
                }
            }
        }
        for _ in 0..m {
            for &(a, b, c) in &triples {
                let (a, b, c) = (ds.getp(a), ds.getp(b), ds.getp(c));
                if a == b {
                    ds.setp(c, a);
                } else if a == c || b == c {
                    ds.setp(a, b);
                }
            }
        }

        let mut e = vec![vec![]; m];
        for &(a, b, c) in &triples {
            let (a, b, c) = (ds.getp(a), ds.getp(b), ds.getp(c));
            if a != b {
                debug_assert!(a != c && b != c);
                e[a].push((b, c));
                e[b].push((a, c));
                e[c].push((a, b));
            }
        }
        for ei in &mut e {
            ei.sort_unstable();
            ei.dedup();
        }

        let mut ans = vec![-1; m];
        let mut ok = true;
        for (i, c) in known {
            let i = ds.getp(i);
            if !assign(i, c, &e, &mut ans) {
                ok = false;
                break;
            }
        }
        for i in 0..m {
            if ok && ds.getp(i) == i && ans[i] <= 0 {
                ok &= dfs(i, &e, &mut ans, &mut HashMap::new());
            }
        }
        if ok {
            let ans = (0..m)
                .map(|i| ans[ds.getp(i)].to_string())
                .collect::<Vec<_>>();
            println!("{}", ans.join(" "));
        } else {
            println!("-1");
        }
    }
}

// the time complexity is not proven
// 148638507	Mar/06/2022 10:54UTC-8	watashi	1616F - Tricolor Triangles	Rust 2021	Accepted	77 ms	800 KB
