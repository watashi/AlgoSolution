use std::{io::*, *};

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
struct Sum {
    count: i64,
    last: i64,
    sum: i64,
    acc: i64, // \sum_{i=1}^n{(n+1-i)*a_i}
}

impl SegTreeMonoid for Sum {
    fn empty(start: i64, end: i64) -> Self {
        Sum {
            count: end - start,
            last: 0,
            sum: 0,
            acc: 0,
        }
    }

    fn append(&self, other: &Self) -> Self {
        Sum {
            count: self.count + other.count,
            last: other.last,
            sum: self.sum + other.sum,
            acc: self.acc + self.sum * other.count + other.acc,
        }
    }
}

#[derive(Clone, Copy)]
struct Add(i64);

impl SegTreeOp<Sum> for Add {
    fn apply<U>(&self, root: &mut SegTree<Sum, U>) {
        let v = &mut root.value;
        v.last += self.0;
        v.sum += v.count * self.0;
        v.acc += (v.count + 1) * v.count / 2 * self.0;
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
    let nmq = read_vec::<i64>();
    let (n, m, q) = (nmq[0], nmq[1], nmq[2]);
    let mut a = read_vec::<i64>();
    for i in (1..a.len()).rev() {
        a[i] -= a[i - 1];
    }

    let b = read_vec::<i64>();
    let mut b0 = b[0];
    let mut t = SegTree::<Sum, Add>::new(1, m);
    for (i, j) in b.windows(2).enumerate() {
        let i = i as i64;
        t.apply(i + 1, i + 2, Add(j[1] - j[0]));
    }

    let mut cout = BufWriter::new(stdout());
    for _ in 0..q {
        if let [ty, k, d] = read_vec::<i64>()[..] {
            if ty == 1 {
                for i in a.iter_mut().rev().take(k as usize) {
                    *i += d;
                }
            } else {
                if k == m {
                    b0 += d;
                }
                t.apply(cmp::max(1, m - k), m, Add(d));
            }

            let mut count = n + m - 1;
            let mut ans = (a[0] + b0) * count;
            count -= 1;
            let mut prev = 1;
            for &ai in a.iter().skip(1) {
                let next = if prev < m {
                    t.bsearch(prev, m, &|i| i.last > ai)
                } else {
                    m
                };
                let s = if prev < next {
                    t.query(prev, next)
                } else {
                    Sum::empty(prev, next)
                };
                // eprintln!("{}: {} => {}: ({}, {}, {})", ai, prev, next, s.last, s.sum, s.acc);
                count -= s.count;
                ans += s.acc;
                ans += s.sum * count;
                ans += ai * count;
                count -= 1;
                prev = next;
            }
            if prev < m {
                ans += t.query(prev, m).acc;
            }
            writeln!(cout, "{}", ans).ok();
        }
    }
}

// 142921862	Jan/15/2022 22:56UTC-8	watashi	1609G - A Stroll Around the Matrix	Rust 2021	Accepted	4851 ms	20200 KB
