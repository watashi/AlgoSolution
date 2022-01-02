use std::*;

pub trait SegTreeMonoid: Copy {
    fn empty(start: i64, end: i64) -> Self;
    fn append(&self, other: &Self) -> Self;
}

pub trait SegTreeOp<T>: Copy {
    fn apply<U>(&self, root: &mut SegTree<T, U>);
    fn combine(&mut self, other: &Self);
}

pub struct SegTree<T, Op> {
    start: i64,
    end: i64,
    value: T,
    op: Option<Op>,
    left: Option<Box<Self>>,
    right: Option<Box<Self>>,
}

impl<T: SegTreeMonoid, Op: SegTreeOp<T>> SegTree<T, Op> {
    pub fn new(start: i64, end: i64) -> Self {
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
        op.apply(self);
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
        if self.left.is_none() {
            let mid = self.start + (self.end - self.start) / 2;
            self.left = Some(Box::new(Self::new(self.start, mid)));
            self.right = Some(Box::new(Self::new(mid, self.end)));
        }
        if self.right.is_none() {}
        let left = self.left.as_deref_mut().unwrap();
        let right = self.right.as_deref_mut().unwrap();
        if let Some(op) = self.op {
            left.lazy_apply(op);
            right.lazy_apply(op);
            self.op = None;
        }
        (left, right)
    }

    pub fn apply(&mut self, start: i64, end: i64, op: Op) {
        debug_assert!(!(end <= self.start || self.end <= start));
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

    pub fn query(&mut self, start: i64, end: i64) -> T {
        debug_assert!(!(end <= self.start || self.end <= start));
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

    pub fn bsearch<F>(&mut self, start: i64, end: i64, f: &F) -> i64
    where
        F: Fn(&T) -> bool,
    {
        if !f(&self.value) {
            end
        } else if self.is_leaf() {
            self.start
        } else {
            let (left, right) = self.force();
            if end <= left.end {
                left.bsearch(start, end, f)
            } else if right.start <= start {
                right.bsearch(start, end, f)
            } else {
                let ret = left.bsearch(start, end, f);
                if ret != end {
                    ret
                } else {
                    right.bsearch(start, end, f)
                }
            }
        }
    }
}

#[derive(Clone, Copy)]
struct Max(i64);

impl SegTreeMonoid for Max {
    fn empty(_: i64, end: i64) -> Self {
        Max(end - 1)
    }

    fn append(&self, other: &Self) -> Self {
        *other
    }
}

#[derive(Clone, Copy)]
struct Add(i64);

impl SegTreeOp<Max> for Add {
    fn apply<U>(&self, root: &mut SegTree<Max, U>) {
        root.value.0 += self.0;
    }

    fn combine(&mut self, other: &Self) {
        self.0 += other.0;
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
    const M: i64 = 1_000_000_001;
    let n = read_line().trim().parse().unwrap();
    let mut t: SegTree<Max, Add> = SegTree::new(0, M);
    let mut y = 0;
    let mut z = vec![];
    for _ in 0..n {
        let v = read_line().trim().parse().unwrap();
        let ge = t.bsearch(0, M, &|i| i.0 >= v);
        let gt = t.bsearch(0, M, &|i| i.0 > v);
        if ge > 0 {
            t.apply(0, ge, Add(1));
        }
        if gt < M {
            t.apply(gt, M, Add(-1));
        }

        read_line();
        for x in read_vec::<i64>() {
            y += x;
            if y >= M {
                y -= M;
            }
            y = t.query(y, y + 1).0;
            z.push(y.to_string());
        }
    }
    println!("{}", z[..].join("\n"));
}

// 141334286	Jan/01/2022 08:48UTC-8	watashi	1614E - Divan and a Cottage	Rust 2021	Happy New Year!	1840 ms	612300 KB
