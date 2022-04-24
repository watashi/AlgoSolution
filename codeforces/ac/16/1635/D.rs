use std::*;
 
type MIntImpl = u64;
 
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
 
type MInt = MIntT<1_000_000_007>;
 
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
    let [n, p]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
    let mut v = read_vec::<u32>();
    v.sort_unstable();
    let mut dp = vec![MInt::from(0); 32.max(p + 1)];
    while let Some(mut i) = v.pop() {
        let mut ok = true;
        let b = u32::BITS - i.leading_zeros();
        while ok && i > 1 {
            if i % 4 == 0 {
                i /= 4;
            } else if i % 2 != 0 {
                i /= 2;
            } else {
                break;
            }
            ok &= v.binary_search(&i).is_err();
        }
        if ok {
            dp[b as usize] += 1.into();
        }
    }
 
    let mut ans = dp[1];
    for i in 2..=p {
        dp[i] = dp[i] + dp[i - 1] + dp[i - 2];
        ans += dp[i];
    }
    println!("{}", ans.0);
}

// 150670476	Mar/23/2022 22:43UTC-7	watashi	1635D - Infinite Set	Rust 2021	Accepted	61 ms	6200 KB

