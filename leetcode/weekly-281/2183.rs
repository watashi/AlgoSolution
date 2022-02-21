use std::*;

struct PrimeTable(Vec<usize>);

impl PrimeTable {
    fn new(n: usize) -> Self {
        let mut p = vec![0; cmp::max(2, n)];
        p[1] = 1;
        for i in 2..n {
            if p[i] == 0 {
                p[i] = i;
                for j in (i.saturating_mul(i)..n).step_by(i) {
                    if p[j] == 0 {
                        p[j] = i;
                    }
                }
            }
        }
        PrimeTable(p)
    }

    fn prime_factors(&self, mut n: usize) -> Vec<(usize, u32)> {
        let p = &self.0;
        debug_assert!(0 < n && n < p.len());
        let mut d: Vec<(usize, u32)> = vec![];
        while n > 1 {
            if d.is_empty() || d.last().unwrap().0 != p[n] {
                d.push((p[n], 1));
            } else {
                d.last_mut().unwrap().1 += 1
            }
            n /= p[n];
        }
        d
    }

    fn factors(&self, n: usize) -> Vec<usize> {
        fn gen(mut i: slice::Iter<(usize, u32)>, mut x: usize, f: &mut Vec<usize>) {
            match i.next() {
                Some(&(p, r)) => {
                    for _ in 0..r {
                        gen(i.clone(), x, f);
                        x *= p;
                    }
                    gen(i, x, f);
                }
                None => {
                    f.push(x);
                }
            }
        }
        let d = self.prime_factors(n);
        let mut f = vec![];
        gen(d.iter(), 1, &mut f);
        f
    }
}

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

impl Solution {
    pub fn cout_pairs(nums: Vec<i32>, k: i32) -> i64 {
        let k = k as i64;
        let pt = PrimeTable::new(100_100);
        let mut c = collections::HashMap::<i64, i64>::new();
        for i in nums {
            *c.entry(i as i64).or_default() += 1;
        }
        let mut cc = vec![0; 100_100];
        let mut ans = 0;
        for (&x, &y) in c.iter() {
            if x * x % k == 0 {
                ans += y * (y - 1);
            }
            for i in pt.factors(x as usize) {
                cc[i] += y;
            }
        }
        for (&x, &y) in c.iter() {
            let g = gcd(x, k);
            ans += y * cc[(k / g) as usize];
            if x * x % k == 0 {
                ans -= y * y;
            }
        }
        ans / 2
    }
}
