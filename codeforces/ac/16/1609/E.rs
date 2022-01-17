use std::{cmp::*, *};

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

#[derive(Clone, Copy, Debug)]
struct Stat {
    a: i32,
    b: i32,
    c: i32,
    noab: i32,
    nobc: i32,
    noabc: i32,
}

impl SegTreeMonoid for Stat {
    fn empty(start: i64, end: i64) -> Self {
        Stat {
            a: (end - start) as i32,
            b: 0,
            c: 0,
            noab: 0,
            nobc: 0,
            noabc: 0,
        }
    }

    fn append(&self, other: &Self) -> Self {
        Stat {
            a: self.a + other.a,
            b: self.b + other.b,
            c: self.c + other.c,
            noab: min(self.a + other.noab, self.noab + other.b),
            nobc: min(self.b + other.nobc, self.nobc + other.c),
            noabc: min(
                min(self.a + other.noabc, self.noab + other.nobc),
                self.noabc + other.c,
            ),
        }
    }
}

#[derive(Clone, Copy)]
struct Update(u8);

impl SegTreeOp<Stat> for Update {
    fn apply<U>(&self, root: &mut SegTree<Stat, U>) {
        debug_assert!(root.end - root.start == 1);
        let value = &mut root.value;
        *value = Stat::empty(root.start, root.end);
        value.a = 0;
        match self.0 {
            b'a' => value.a = 1,
            b'b' => value.b = 1,
            b'c' => value.c = 1,
            _ => panic!(),
        }
    }

    fn combine(&mut self, _other: &Self) {
        panic!();
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
    let nq = read_vec::<i64>();
    let (n, q) = (nq[0], nq[1]);
    let s = read_line();
    let mut t = SegTree::<Stat, Update>::new(1, n + 1);
    for (i, &c) in (1..=n).zip(s.as_bytes()) {
        t.apply(i, i + 1, Update(c));
    }

    let mut ans = vec![];
    for _ in 0..q {
        if let [i, c] = &read_vec::<String>()[..] {
            let i = i.parse().unwrap();
            let c = c.as_bytes()[0];
            t.apply(i, i + 1, Update(c));
            let ret = t.query(1, n + 1);
            // eprintln!("{:?}", ret);
            ans.push(ret.noabc.to_string());
        }
    }
    println!("{}", ans[..].join("\n"));
}

// 143067701	Jan/16/2022 22:09UTC-8	watashi	1609E - William The Oblivious	Rust 2021	Accepted	155 ms	22100 KB
