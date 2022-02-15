use std::*;

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
        self.0[x] = y;
        if x != y {
            Some((x, y))
        } else {
            None
        }
    }
}

pub struct EdmondsBlossom {
    e: Vec<Vec<usize>>,
    q: Vec<usize>,
    ds: DisjointSet,
    path: Vec<Option<Vec<usize>>>,
    vmatch: Vec<Option<usize>>,
}

impl EdmondsBlossom {
    fn enqueue(&mut self, mut path: Vec<usize>, w: usize) {
        debug_assert!(self.path[w].is_none());
        path.push(w);
        self.path[w] = Some(path);
        self.q.push(w);
    }

    fn contract_path(&mut self, path: &[usize], p: usize, mut pre: Vec<usize>) {
        for &v in path.iter().rev() {
            let u = self.vmatch[v].unwrap();
            self.ds.setp(u, p);
            self.ds.setp(v, p);
            if self.path[u].is_none() {
                self.enqueue(pre.clone(), u);
            }
            pre.push(u);
        }
    }

    fn contract_blossom(&mut self, v: usize, w: usize) {
        if self.ds.getp(v) == self.ds.getp(w) {
            return;
        }
        let pv = self.path[v].clone().unwrap();
        let pw = self.path[w].clone().unwrap();
        let lcp = pv.iter().zip(&pw).take_while(|(i, j)| i == j).count();
        let p = pv[lcp - 1];
        self.contract_path(&pv[lcp..], p, pw.clone());
        self.contract_path(&pw[lcp..], p, pv.clone());
    }

    fn augment(&mut self, v: usize, w: usize) {
        let path = self.path[v].as_ref().unwrap();
        // eprintln!("augment: {:?} -> {}", path, w);
        for pair in path.windows(2) {
            if let &[i, j] = pair {
                let k = self.vmatch[j].unwrap();
                self.vmatch[i] = Some(k);
                self.vmatch[k] = Some(i);
            }
        }
        self.vmatch[v] = Some(w);
        self.vmatch[w] = Some(v);
    }

    fn bfs(&mut self, root: usize) -> bool {
        self.q.clear();
        self.ds.clear();
        self.path.fill(None);

        self.q.push(root);
        self.path[root] = Some(vec![root]);
        while let Some(v) = self.q.pop() {
            let ev = self.e[v].clone();
            for w in ev {
                // eprintln!("{} -> {}: {:?}: {:?}", v, w, self.vmatch[w], self.path[w]);
                if self.path[w].is_some() {
                    self.contract_blossom(v, w);
                } else if let Some(u) = self.vmatch[w] {
                    if self.path[u].is_none() {
                        self.enqueue(self.path[v].clone().unwrap(), u);
                    }
                } else {
                    self.augment(v, w);
                    return true;
                }
            }
        }
        false
    }

    pub fn solve(e: Vec<Vec<usize>>) -> Vec<Option<usize>> {
        let n = e.len();
        let mut ret = Self {
            e: e,
            ds: DisjointSet::new(n),
            q: vec![],
            path: vec![None; n],
            vmatch: vec![None; n],
        };
        for i in 0..n {
            if ret.vmatch[i].is_none() {
                ret.bfs(i);
            }
        }
        ret.vmatch
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

fn main() {
    let n = read_line().trim().parse().unwrap();
    let mut e = vec![vec![]; n];
    while let [a, b] = read_vec::<usize>()[..] {
        e[a - 1].push(b - 1);
        e[b - 1].push(a - 1);
    }
    let m = EdmondsBlossom::solve(e);
    println!("{}", m.iter().filter(|i| i.is_some()).count());
    for (i, j) in m.into_iter().enumerate() {
        match j {
            Some(j) if i < j => println!("{} {}", i + 1, j + 1),
            _ => {}
        }
    }
}

// 9650248	07:12:05    15 Feb 2022	watashi	1099. Work Scheduling	Rust 1.58 x64	Accepted    0.031	848 KB
