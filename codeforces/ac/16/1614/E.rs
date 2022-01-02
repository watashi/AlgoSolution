use std::*;

pub struct SegTree {
    start: i32,
    end: i32,
    max: i32,
    add: i32,
    left: Option<Box<Self>>,
    right: Option<Box<Self>>,
}

impl SegTree {
    pub fn new(start: i32, end: i32) -> Self {
        SegTree {
            start: start,
            end: end,
            max: end - 1,
            add: 0,
            left: None,
            right: None,
        }
    }

    pub fn is_leaf(&self) -> bool {
        self.end - self.start == 1
    }

    fn lazy_apply(&mut self, add: i32) {
        if add != 0 {
            self.max += add;
            self.add += add;
        }
    }

    fn force(&mut self) -> (&mut Self, &mut Self) {
        debug_assert!(!self.is_leaf());
        if self.left.is_none() {
            let mid = self.start + (self.end - self.start) / 2;
            self.left = Some(Box::new(Self::new(self.start, mid)));
            self.right = Some(Box::new(Self::new(mid, self.end)));
        }
        let left = self.left.as_deref_mut().unwrap();
        let right = self.right.as_deref_mut().unwrap();
        if self.add != 0 {
            left.lazy_apply(self.add);
            right.lazy_apply(self.add);
            self.add = 0;
        }
        (left, right)
    }

    pub fn apply(&mut self, start: i32, end: i32, add: i32) {
        debug_assert!(!(end <= self.start || self.end <= start));
        if start <= self.start && self.end <= end {
            self.lazy_apply(add);
        } else {
            let (left, right) = self.force();
            if start < left.end {
                left.apply(start, end, add);
            }
            if right.start < end {
                right.apply(start, end, add);
            }
            self.max = right.max;
        }
    }

    pub fn query(&mut self, index: i32) -> i32 {
        debug_assert!(self.start <= index && index < self.end);
        let mut t = self;
        while !t.is_leaf() {
            let (left, right) = t.force();
            if index < left.end {
                t = left;
            } else {
                t = right;
            }
        }
        t.max
    }

    pub fn bsearch(&mut self, start: i32, end: i32, x: i32) -> i32 {
        debug_assert!(!(end <= self.start || self.end <= start));
        if self.max < x {
            end
        } else if self.is_leaf() {
            self.start
        } else {
            let (left, right) = self.force();
            if end <= left.end {
                left.bsearch(start, end, x)
            } else if right.start <= start {
                right.bsearch(start, end, x)
            } else {
                let ret = left.bsearch(start, end, x);
                if ret != end {
                    ret
                } else {
                    right.bsearch(start, end, x)
                }
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

fn main() {
    const M: i32 = 1_000_000_001;
    let n = read_line().trim().parse().unwrap();
    let mut t: SegTree = SegTree::new(0, M);
    let mut y = 0;
    let mut z = vec![];
    for _ in 0..n {
        let v = read_line().trim().parse().unwrap();
        let ge = t.bsearch(0, M, v);
        let gt = t.bsearch(0, M, v + 1);
        if ge > 0 {
            t.apply(0, ge, 1);
        }
        if gt < M {
            t.apply(gt, M, -1);
        }

        read_line();
        for x in read_vec::<i32>() {
            y += x;
            if y >= M {
                y -= M;
            }
            y = t.query(y);
            z.push(y.to_string());
        }
    }
    println!("{}", z[..].join("\n"));
}

// 141336944	Jan/01/2022 09:21UTC-8	watashi	1614E - Divan and a Cottage	Rust 2021	Happy New Year!	1653 ms	463100 KB
