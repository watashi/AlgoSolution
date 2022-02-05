use std::*;

pub struct BIT<T>(Vec<T>);

impl<T: Clone + Copy + Default + ops::AddAssign + ops::Sub<Output = T>> BIT<T> {
    pub fn new(n: usize) -> Self {
        Self(vec![Default::default(); n + 1])
    }

    pub fn add(&mut self, mut i: usize, v: T) {
        i += 1;
        while i < self.0.len() {
            self.0[i] += v;
            i = (i | (i - 1)) + 1;
        }
    }

    pub fn partial_sum(&self, mut i: usize) -> T {
        let mut s = Default::default();
        while i > 0 {
            s += self.0[i];
            i = i & (i - 1);
        }
        s
    }

    pub fn sum(&self, range: impl ops::RangeBounds<usize>) -> T {
        use ops::Bound::*;
        let start = match range.start_bound() {
            Included(&i) => i,
            Excluded(&i) => i + 1,
            Unbounded => 0,
        };
        let end = match range.end_bound() {
            Included(&i) => i + 1,
            Excluded(&i) => i,
            Unbounded => self.0.len() - 1,
        };
        if start < end {
            self.partial_sum(end) - self.partial_sum(start)
        } else {
            Default::default()
        }
    }

    pub fn get(&self, i: usize) -> T {
        self.sum(i..=i)
    }

    pub fn set(&mut self, i: usize, v: T) {
        self.add(i, v - self.get(i))
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
    let (n, m) = {
        let nm = read_vec::<usize>();
        (nm[0], nm[1])
    };

    let mut e = vec![vec![]; n + 1];
    let s = read_line();
    let mut v = vec![];
    for (i, c) in (1..=n).zip(s.trim().chars()) {
        if c == '(' {
            v.push(i);
        } else if let Some(j) = v.pop() {
            let &k = v.last().unwrap_or(&0);
            e[k].push(j);
        }
    }
    for j in v {
        let ej = mem::replace(&mut e[j], vec![]);
        e[0].extend(ej);
    }

    let mut parent = (0..=n).collect::<Vec<_>>();
    let mut bit = BIT::new(n + 1);
    let mut d = e
        .iter()
        .map(|i| {
            let mut di = BIT::new(i.len());
            for j in 0..i.len() {
                di.add(j, 1i64);
            }
            di
        })
        .collect::<Vec<_>>();
    for i in 0..=n {
        for &j in &e[i] {
            parent[j] = i;
        }
    }
    for i in 1..=n {
        if parent[i] != i {
            let di = d[i].sum(..);
            bit.add(i, di * (di - 1) / 2 + 1);
        }
    }

    let mut ans = vec![];
    for _ in 0..m {
        match &read_vec::<usize>()[..] {
            &[1, l, _] => {
                let p = parent[l];
                bit.add(l, -1);
                let l = e[p].binary_search(&l).unwrap();
                d[p].add(l, -1);
                bit.add(p, -d[p].sum(..));
            }
            &[2, l, r] => {
                let p = parent[l];
                let mut cnt = bit.sum(l..r);
                let l = e[p].binary_search(&l).unwrap();
                let r = e[p].binary_search(&r).err().unwrap();
                let dp = d[p].sum(l..r);
                cnt += dp * (dp - 1) / 2;
                ans.push(cnt.to_string());
            }
            _ => {}
        }
    }
    println!("{}", ans[..].join("\n"));
}

// 145188331	Feb/04/2022 21:31UTC-8	watashi	1625E2 - Cats on the Upgrade (hard version)	Rust 2021	Accepted	218 ms	52700 KB
