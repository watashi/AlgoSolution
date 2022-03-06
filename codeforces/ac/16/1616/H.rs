use std::*;

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

#[derive(Clone, Copy, Debug, Default)]
pub struct MIntT<const M: u64>(u64);

impl<const M: u64> From<u64> for MIntT<M> {
    fn from(x: u64) -> Self {
        Self(x % M)
    }
}

impl<const M: u64> ops::Add for MIntT<M> {
    type Output = Self;
    fn add(mut self, rhs: Self) -> Self::Output {
        self += rhs;
        self
    }
}

impl<const M: u64> ops::AddAssign for MIntT<M> {
    fn add_assign(&mut self, rhs: Self) {
        self.0 += rhs.0;
        if self.0 >= M {
            self.0 -= M;
        }
    }
}

impl<const M: u64> ops::Mul for MIntT<M> {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        Self(self.0 * rhs.0 % M)
    }
}

impl<const M: u64> ops::MulAssign for MIntT<M> {
    fn mul_assign(&mut self, rhs: Self) {
        *self = *self * rhs;
    }
}

type MInt = MIntT<998244353>;

fn nonempty(x: &Vec<u32>) -> MInt {
    let mut b = 0.into();
    for _ in 0..x.len() {
        b = b * 2.into() + 1.into();
    }
    b
}

fn gao(mut b: u32, k: u32, x: &Vec<u32>, y: &Vec<u32>) -> MInt {
    if b == 0 || x.is_empty() || y.is_empty() {
        nonempty(&x) * nonempty(&y)
    } else {
        b -= 1;
        let (x0, x1) = x.iter().copied().partition(|i| i & (1 << b) == 0);
        let (y0, y1) = y.iter().copied().partition(|i| i & (1 << b) == 0);
        if k & (1 << b) == 0 {
            gao(b, k, &x0, &y0) + gao(b, k, &x1, &y1)
        } else {
            let mut ret = 0.into();
            let c01 = gao(b, k, &x0, &y1);
            let c10 = gao(b, k, &x1, &y0);
            // 4
            ret += c01 * c10;
            // 3
            ret += c01 * (nonempty(&x1) + nonempty(&y0));
            ret += c10 * (nonempty(&x0) + nonempty(&y1));
            // 2
            ret += nonempty(&x0) * nonempty(&y0);
            ret += nonempty(&x1) * nonempty(&y1);
            ret += c01;
            ret += c10;
            ret
        }
    }
}

fn main() {
    let k = read_vec::<u32>()[1];
    let b = u32::BITS - k.leading_zeros();
    let mut m = collections::HashMap::<_, Vec<_>>::new();
    for i in read_vec::<u32>() {
        m.entry(i >> b).or_default().push(i);
    }

    let mut ans = MInt::from(0);
    for i in m.values() {
        if b == 0 {
            ans += nonempty(i);
        } else {
            let b = b - 1;
            let (x, y) = i.iter().copied().partition(|&i| i & (1 << b) == 0);
            ans += nonempty(&x);
            ans += nonempty(&y);
            ans += gao(b, k, &x, &y);
        }
    }
    println!("{}", ans.0);
}

// 144615621	Jan/30/2022 21:41UTC-8	watashi	1616H - Keep XOR Low	Rust 2021	Accepted	93 ms	17900 KB
