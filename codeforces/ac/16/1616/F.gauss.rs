use std::*;

type MIntImpl = u8;

#[derive(Clone, Copy, Debug, Default)]
pub struct MIntT<const M: MIntImpl>(MIntImpl);

impl<const M: MIntImpl> From<MIntImpl> for MIntT<M> {
    fn from(x: MIntImpl) -> Self {
        Self(x % M)
    }
}

impl<const M: MIntImpl> ops::Add for MIntT<M> {
    type Output = Self;
    fn add(mut self, rhs: Self) -> Self::Output {
        self += rhs;
        self
    }
}

impl<const M: MIntImpl> ops::AddAssign for MIntT<M> {
    fn add_assign(&mut self, rhs: Self) {
        self.0 += rhs.0;
        if self.0 >= M {
            self.0 -= M;
        }
    }
}

impl<const M: MIntImpl> ops::Sub for MIntT<M> {
    type Output = Self;
    fn sub(mut self, rhs: Self) -> Self::Output {
        self -= rhs;
        self
    }
}

impl<const M: MIntImpl> ops::SubAssign for MIntT<M> {
    fn sub_assign(&mut self, rhs: Self) {
        if self.0 < rhs.0 {
            self.0 += M;
        }
        self.0 -= rhs.0;
    }
}

impl<const M: MIntImpl> ops::Mul for MIntT<M> {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        Self(self.0 * rhs.0 % M)
    }
}

impl<const M: MIntImpl> ops::MulAssign for MIntT<M> {
    fn mul_assign(&mut self, rhs: Self) {
        *self = *self * rhs;
    }
}

impl<const M: MIntImpl> ops::Div for MIntT<M> {
    type Output = Self;
    fn div(self, rhs: Self) -> Self::Output {
        self * rhs.inv()
    }
}

impl<const M: MIntImpl> ops::DivAssign for MIntT<M> {
    fn div_assign(&mut self, rhs: Self) {
        *self *= rhs.inv();
    }
}

impl<const M: MIntImpl> MIntT<M> {
    fn pow(&self, mut b: u64) -> Self {
        let mut a = *self;
        let mut c = 1.into();
        loop {
            if (b & 1) != 0 {
                c *= a;
            }
            b >>= 1;
            if b == 0 {
                break;
            }
            a *= a;
        }
        c
    }

    fn inv(&self) -> Self {
        self.pow((M - 2) as u64)
    }
}

type M3 = MIntT<3>;

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

pub trait GaussLuOps:
    Copy
    + Sized
    + ops::Add<Output = Self>
    + ops::Sub<Output = Self>
    + ops::Mul<Output = Self>
    + ops::Div<Output = Self>
{
    fn zero() -> Self;
    fn is_zero(&self) -> bool;
    fn pivot(&self, rhs: &Self) -> bool;
}

impl GaussLuOps for M3 {
    fn zero() -> Self {
        Self(0)
    }

    fn is_zero(&self) -> bool {
        self.0 == 0
    }

    fn pivot(&self, rhs: &Self) -> bool {
        self.0 > rhs.0
    }
}

pub struct GaussLu<T> {
    r: Vec<usize>,
    c: Vec<usize>,
    lu: Vec<Vec<T>>,
    rank: usize,
}

impl<T: GaussLuOps> GaussLu<T> {
    pub fn new(mut a: Vec<Vec<T>>) -> Self {
        let nr = a.len();
        let nc = if nr > 0 { a[0].len() } else { 0 };
        let mut r = (0..nr).collect::<Vec<_>>();
        let mut c = (0..nc).collect::<Vec<_>>();
        let mut k = 0;
        let mut c0 = nc;
        while k < nr && k < c0 {
            let mut ii = k;
            for i in k..nr {
                if a[i][k].pivot(&a[ii][k]) {
                    ii = i;
                }
            }
            if a[ii][k].is_zero() {
                c0 -= 1;
                c.swap(k, c0);
                for ai in &mut a {
                    ai.swap(k, c0);
                }
                continue;
            }

            r.swap(k, ii);
            a.swap(k, ii);
            for i in k + 1..nr {
                if a[i][k].is_zero() {
                    continue;
                }
                a[i][k] = a[i][k] / a[k][k];
                for j in k + 1..nc {
                    a[i][j] = a[i][j] - a[i][k] * a[k][j];
                }
            }
            k += 1;
        }
        Self {
            r: r,
            c: c,
            lu: a,
            rank: k,
        }
    }

    pub fn solve(&self, b: &Vec<T>) -> Option<Vec<T>> {
        debug_assert!(b.len() == self.r.len());
        let (nr, nc) = (self.r.len(), self.c.len());
        let mut y = self.r.iter().map(|&i| b[i]).collect::<Vec<_>>();
        for i in 0..nr {
            for j in 0..i.min(nc) {
                y[i] = y[i] - self.lu[i][j] * y[j];
            }
        }
        for i in self.rank..nr {
            if !y[i].is_zero() {
                return None;
            }
        }
        y.truncate(self.rank);
        // simply set all free variables to 0
        y.resize(nc, T::zero());

        for i in (0..self.rank).rev() {
            for j in i + 1..self.rank {
                y[i] = y[i] - self.lu[i][j] * y[j];
            }
            y[i] = y[i] / self.lu[i][i];
        }

        let mut x = vec![T::zero(); nc];
        for (i, &ci) in self.c.iter().enumerate() {
            x[ci] = y[i];
        }
        Some(x)
    }
}

fn main() {
    let re = read_line().trim().parse().unwrap();
    for _ in 0..re {
        let [n, m]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
        let mut eid = vec![vec![None; n]; n];
        let mut f = vec![vec![M3::from(0); m]];
        let mut g = vec![M3::from(0)];
        for i in 0..m {
            if let [a, b, c] = read_vec::<i32>()[..] {
                let a = a as usize - 1;
                let b = b as usize - 1;
                eid[a][b] = Some(i);
                eid[b][a] = Some(i);
                if c > 0 {
                    let mut fi = vec![M3::from(0); m];
                    fi[i] = M3::from(1);
                    f.push(fi);
                    g.push(M3::from(c as u8 - 1));
                }
            }
        }

        for i in 0..n {
            for j in 0..i {
                for k in 0..j {
                    if let (Some(a), Some(b), Some(c)) = (eid[i][j], eid[i][k], eid[j][k]) {
                        let mut fi = vec![M3::from(0); m];
                        fi[a] = M3::from(1);
                        fi[b] = M3::from(1);
                        fi[c] = M3::from(1);
                        f.push(fi);
                        g.push(M3::from(0));
                    }
                }
            }
        }
        let lu = GaussLu::new(f);
        if let Some(ans) = lu.solve(&g) {
            let ans = ans
                .into_iter()
                .map(|i| (i.0 + 1).to_string())
                .collect::<Vec<_>>();
            println!("{}", ans.join(" "));
        } else {
            println!("-1");
        }
    }
}

// 148648063	Mar/06/2022 13:59UTC-8	watashi	1616F - Tricolor Triangles	Rust 2021	Accepted	78 ms	1000 KB
