use std::{collections::*, *};

type SegTreeIndex = usize;

pub trait SegTreeMonoid: Copy {
    fn empty(start: SegTreeIndex, end: SegTreeIndex) -> Self;
    fn append(&self, other: &Self) -> Self;
}

pub trait SegTreeOp<T>: Copy {
    fn apply(&self, start: SegTreeIndex, end: SegTreeIndex, value: &mut T);
    fn combine(&mut self, other: &Self);
}

pub struct SegTree<T, Op> {
    start: SegTreeIndex,
    end: SegTreeIndex,
    value: T,
    op: Option<Op>,
    left: Option<Box<Self>>,
    right: Option<Box<Self>>,
}

impl<T: SegTreeMonoid, Op: SegTreeOp<T>> SegTree<T, Op> {
    pub fn new(start: SegTreeIndex, end: SegTreeIndex) -> Self {
        SegTree {
            start: start,
            end: end,
            value: T::empty(start, end),
            op: None,
            left: None,
            right: None,
        }
    }

    pub fn is_leaf(&self) -> bool {
        self.end - self.start == 1
    }

    fn lazy_apply(&mut self, op: Op) {
        op.apply(self.start, self.end, &mut self.value);
        if !self.is_leaf() {
            match self.op.as_mut() {
                Some(x) => {
                    x.combine(&op);
                }
                None => self.op = Some(op),
            }
        }
    }

    fn force(&mut self) -> (&mut Self, &mut Self) {
        debug_assert!(!self.is_leaf());
        if self.left.is_none()
        /* && self.right.is_none() */
        {
            let mid = (self.start + self.end) / 2;
            self.left = Some(Box::new(Self::new(self.start, mid)));
            self.right = Some(Box::new(Self::new(mid, self.end)));
        }
        let left = self.left.as_deref_mut().unwrap();
        let right = self.right.as_deref_mut().unwrap();
        if let Some(op) = self.op {
            left.lazy_apply(op);
            right.lazy_apply(op);
            self.op = None;
        }
        (left, right)
    }

    pub fn apply(&mut self, start: SegTreeIndex, end: SegTreeIndex, op: Op) {
        debug_assert!(start < self.end && self.start < end && start < end);
        if start <= self.start && self.end <= end {
            self.lazy_apply(op);
        } else {
            let (left, right) = self.force();
            if start < left.end {
                left.apply(start, end, op);
            }
            if right.start < end {
                right.apply(start, end, op);
            }
            self.value = left.value.append(&right.value);
        }
    }

    pub fn query(&mut self, start: SegTreeIndex, end: SegTreeIndex) -> T {
        debug_assert!(start < self.end && self.start < end && start < end);
        if start <= self.start && self.end <= end {
            self.value
        } else {
            let (left, right) = self.force();
            if end <= left.end {
                left.query(start, end)
            } else if right.start <= start {
                right.query(start, end)
            } else {
                left.query(start, end).append(&right.query(start, end))
            }
        }
    }
}

pub struct TreeDecomposition {
    root: usize,
    parent: Vec<usize>,
    size: Vec<usize>,
    // invariant: chain[start[i]][index[i]] == i
    start: Vec<usize>,
    index: Vec<usize>,
    chain: Vec<Vec<usize>>,
    // invariant: id[ts[i]] == i
    id: Vec<usize>,
    ts: Vec<usize>, // timestamp, index used in SegTree
}

pub struct TreeDecompositionIter<'a> {
    td: &'a TreeDecomposition,
    current: usize,
    ancestor: usize,
}

impl<'a> Iterator for TreeDecompositionIter<'a> {
    type Item = (usize, usize); // [a, b)

    fn next(&mut self) -> Option<Self::Item> {
        if self.current == usize::MAX {
            return None;
        }
        let start = self.td.start[self.current];
        if start == self.td.start[self.ancestor] {
            let item = (self.td.ts[self.ancestor], self.td.ts[self.current] + 1);
            self.current = usize::MAX;
            Some(item)
        } else {
            let item = (self.td.ts[start], self.td.ts[self.current] + 1);
            self.current = self.td.parent[start];
            Some(item)
        }
    }
}

// Heavy-Light Decomposition
impl TreeDecomposition {
    fn dfs(&mut self, e: &Vec<Vec<usize>>, v: usize, p: usize) -> usize {
        let mut size = 1;
        for &w in &e[v] {
            if w != p {
                size += self.dfs(e, w, v);
            }
        }
        self.parent[v] = p;
        self.size[v] = size;
        size
    }

    fn decomp(
        &mut self,
        e: &Vec<Vec<usize>>,
        v: usize,
        p: usize,
        k: usize,
        mut ts: usize,
    ) -> usize {
        self.start[v] = k;
        self.index[v] = self.chain[k].len();
        self.chain[k].push(v);
        self.ts[v] = ts;
        self.id[ts] = v;
        ts += 1;

        let mut maxw = v;
        for &w in &e[v] {
            if w != p && (maxw == v || self.size[w] > self.size[maxw]) {
                maxw = w;
            }
        }
        if maxw != v {
            ts = self.decomp(e, maxw, v, k, ts);
        }

        for &w in &e[v] {
            if w != p && w != maxw {
                ts = self.decomp(e, w, v, w, ts);
            }
        }
        ts
    }

    pub fn new(tree: &Vec<Vec<usize>>, root: usize) -> Self {
        let n = tree.len();
        let mut t = Self {
            root: root,
            parent: vec![0; n],
            size: vec![0; n],
            start: vec![0; n],
            index: vec![0; n],
            chain: vec![vec![]; n],
            id: vec![0; n],
            ts: vec![0; n],
        };
        t.dfs(tree, root, root);
        t.decomp(tree, root, root, root, 0);
        t
    }

    pub fn path_to_root(&self, v: usize) -> TreeDecompositionIter {
        TreeDecompositionIter {
            td: &self,
            current: v,
            ancestor: self.root,
        }
    }

    pub fn path_to_ancestor(&self, v: usize, ancestor: usize) -> TreeDecompositionIter {
        debug_assert!(self.lca(v, ancestor) == ancestor);
        TreeDecompositionIter {
            td: &self,
            current: v,
            ancestor: ancestor,
        }
    }

    pub fn lca(&self, a: usize, b: usize) -> usize {
        let mut pa = self.path_to_root(a).collect::<Vec<_>>();
        let mut pb = self.path_to_root(b).collect::<Vec<_>>();
        pa.reverse();
        pb.reverse();
        debug_assert!(pa[0].0 == 0 && pb[0].0 == 0);
        let mut i = 1;
        while i < pa.len() && i < pb.len() && pa[i].0 == pb[i].0 {
            i += 1;
        }
        i -= 1;
        self.id[pa[i].1.min(pb[i].1) - 1]
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

#[derive(Clone, Copy, Debug)]
struct Path {
    len: usize,
    matches: usize,
    total: u64,
    subtotal: u64,
}

impl SegTreeMonoid for Path {
    fn empty(start: SegTreeIndex, end: SegTreeIndex) -> Self {
        Self {
            len: end - start,
            matches: 0,
            total: 0,
            subtotal: 0,
        }
    }

    fn append(&self, other: &Self) -> Self {
        Self {
            len: self.len + other.len,
            matches: self.matches + other.matches,
            total: self.total + other.total,
            subtotal: self.subtotal + other.subtotal,
        }
    }
}

#[derive(Clone, Copy, Debug)]
enum Op {
    PointSetTotal(u64),
    RangeFlip(bool),
}

impl SegTreeOp<Path> for Op {
    fn apply(&self, _start: SegTreeIndex, _end: SegTreeIndex, value: &mut Path) {
        match *self {
            Op::PointSetTotal(x) => {
                debug_assert!(value.len == 1);
                value.total += x;
            }
            Op::RangeFlip(true) => {
                value.matches = value.len - value.matches;
                value.subtotal = value.total - value.subtotal;
            }
            Op::RangeFlip(false) => {}
        }
    }

    fn combine(&mut self, other: &Self) {
        if let (Op::RangeFlip(x), Op::RangeFlip(y)) = (*self, *other) {
            *self = Op::RangeFlip(x ^ y);
        } else {
            panic!("Op::Point* can only be used in point update.");
        }
    }
}

fn is_alternative_to_ancestor(
    td: &TreeDecomposition,
    t: &mut SegTree<Path, Op>,
    v: usize,
    ancestor: usize,
) -> Option<bool> {
    let mut path = Path::empty(td.ts[v], td.ts[v] + 1);
    for (mut start, end) in td.path_to_ancestor(td.parent[v], ancestor) {
        if td.id[start] == ancestor {
            start += 1;
        }
        if start < end {
            path = t.query(start, end).append(&path);
        }
    }
    if path.matches == path.len / 2 {
        Some(path.len % 2 == 0)
    } else {
        None
    }
}

fn augment(td: &TreeDecomposition, t: &mut SegTree<Path, Op>, a: usize, b: usize) {
    // eprintln!("augment({}, {})", a + 1, b + 1);
    let lca = td.lca(a, b);
    for i in [a, b] {
        for (mut start, end) in td.path_to_ancestor(i, lca) {
            if td.id[start] == lca {
                start += 1;
            }
            if start < end {
                t.apply(start, end, Op::RangeFlip(true));
            }
        }
    }
}

fn main() {
    const ROOT: usize = 0;
    let n = read_line().trim().parse().unwrap();
    let mut e = vec![vec![]; n];
    let mut eid = HashMap::new();
    for i in 1..n as u64 {
        if let [a, b] = read_vec::<usize>()[..] {
            let (a, b) = (a - 1, b - 1);
            e[a].push(b);
            e[b].push(a);
            eid.insert((a, b), i);
            eid.insert((b, a), i);
        }
    }
    let td = TreeDecomposition::new(&e, ROOT);
    let mut t = SegTree::<Path, Op>::new(0, n as SegTreeIndex);
    for i in 1..n {
        t.apply(
            td.ts[i],
            td.ts[i] + 1,
            Op::PointSetTotal(eid[&(td.parent[i], i)]),
        );
    }

    let mut orphans = HashSet::new();
    let mut waiting = 1;
    orphans.insert(ROOT);
    loop {
        match read_vec::<usize>()[..] {
            [1, v] => {
                let v = v - 1;
                let p = td.parent[v];
                waiting -= 1;
                if orphans.contains(&p) {
                    // eprintln!("augment1({}, {})", v, p);
                    orphans.remove(&p);
                    t.apply(td.ts[v], td.ts[v] + 1, Op::RangeFlip(true));
                } else {
                    orphans.insert(v);
                }
                if waiting == 0 {
                    let mut leaves = orphans.iter().map(|&i| td.ts[i]).collect::<BTreeSet<_>>();
                    let mut lcas = BTreeSet::new();
                    for (&a, &b) in leaves.iter().zip(leaves.iter().skip(1)) {
                        let lca = td.lca(td.id[a], td.id[b]);
                        lcas.insert((td.ts[lca], a, b));
                    }

                    while let Some(last @ (lca, a, b)) = lcas.iter().next_back().copied() {
                        lcas.remove(&last);
                        if !leaves.contains(&a) || !leaves.contains(&b) {
                            continue;
                        }
                        let pa = is_alternative_to_ancestor(&td, &mut t, td.id[a], td.id[lca]);
                        let pb = is_alternative_to_ancestor(&td, &mut t, td.id[b], td.id[lca]);
                        // eprintln!("check({}, {}, {}) = ({:?}, {:?})", td.id[lca], td.id[a], td.id[b], pa, pb);
                        let mut remove = |ts| {
                            leaves.remove(&ts);
                            if let (Some(&prev), Some(&next)) =
                                (leaves.range(..ts).next_back(), leaves.range(ts..).next())
                            {
                                let new_lca = td.lca(td.id[prev], td.id[next]);
                                lcas.insert((td.ts[new_lca], prev, next));
                            }
                        };
                        match (pa, pb) {
                            (None, None) => {
                                remove(a);
                                remove(b);
                            }
                            (Some(x), Some(y)) if x != y => {
                                remove(a);
                                remove(b);
                                orphans.remove(&td.id[a]);
                                orphans.remove(&td.id[b]);
                                augment(&td, &mut t, td.id[a], td.id[b]);
                            }
                            (None, Some(_)) => {
                                remove(a);
                            }
                            (Some(_), _) => {
                                remove(b);
                            }
                        }
                    }

                    waiting = orphans.len();
                    if waiting == 0 {
                        waiting = 2;
                    }
                }
                // eprintln!("orphans = {:?}", orphans);
                if orphans.is_empty() {
                    println!("{}", t.query(0, n).subtotal);
                } else {
                    println!("0");
                }
            }
            [2] => {
                if orphans.is_empty() {
                    let mut edges = vec![];
                    for i in 1..n {
                        let q = t.query(i, i + 1);
                        if q.subtotal > 0 {
                            edges.push(q.subtotal);
                        }
                    }
                    edges.sort_unstable();
                    println!(
                        "{} {}",
                        edges.len(),
                        edges.iter().map(|i| i.to_string()).collect::<Vec<_>>()[..].join(" ")
                    );
                } else {
                    println!("0");
                }
            }
            _ => {
                println!("0");
                break;
            }
        }
    }
}

// 150096479	Mar/18/2022 23:19UTC-7	watashi	1633F - Perfect Matching	Rust 2021	Accepted	4554 ms	111800 KB
