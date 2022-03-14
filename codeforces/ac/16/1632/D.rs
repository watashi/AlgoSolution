use std::*;

type SegTreeIndex = usize;

pub trait SegTreeMonoid: Copy {
    fn empty(start: SegTreeIndex, end: SegTreeIndex) -> Self;
    fn append(&self, other: &Self) -> Self;
}

pub trait SegTreeOp<T>: Copy {
    fn apply(&self, start: SegTreeIndex, end: SegTreeIndex, value: &mut T);
    fn combine(&mut self, other: &Self);
}

impl<T: SegTreeMonoid> SegTreeOp<T> for T {
    fn apply(&self, start: SegTreeIndex, end: SegTreeIndex, value: &mut T) {
        *value = value.append(self);
    }

    fn combine(&mut self, other: &Self) {
        *self = self.append(other);
    }
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

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

#[derive(Clone, Copy)]
struct Gcd(i32);

impl SegTreeMonoid for Gcd {
    fn empty(_start: SegTreeIndex, _end: SegTreeIndex) -> Self {
        Gcd(0)
    }

    fn append(&self, other: &Self) -> Self {
        Gcd(gcd(self.0, other.0))
    }
}

fn main() {
    read_line();
    let a = read_vec::<i32>();
    let n = a.len();
    let mut t = SegTree::new(0, n);
    let mut c = 0;
    let mut s = vec![];
    for (i, ai) in a.into_iter().enumerate() {
        let (mut lo, mut hi) = (0, i);
        t.apply(i, i + 1, Gcd(ai));
        while lo < hi {
            let mi = (lo + hi) / 2;
            let g = t.query(mi, i + 1).0;
            if g < (i + 1 - mi) as i32 {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        // println!("{} {}", hi, t.query(hi, i + 1).0);
        if t.query(hi, i + 1).0 == (i + 1 - hi) as i32 {
            c += 1;
            t.apply(i, i + 1, Gcd(1));
        }
        s.push(c.to_string());
    }
    println!("{}", s.join(" "));
}

// 149571846	Mar/13/2022 19:34UTC-7	watashi	1632D - New Year Concert	Rust 2021	Accepted	1029 ms	35600 KB
