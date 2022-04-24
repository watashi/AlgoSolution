use std::*;
 
pub struct ExtDisjointSet(Vec<i32>);
 
impl ExtDisjointSet {
    pub fn new(n: usize) -> Self {
        Self((0..n as i32).collect())
    }
 
    pub fn getp(&mut self, x: i32) -> i32 {
        if x < 0 {
            !self.getp(!x)
        } else {
            let i = x as usize;
            if self.0[i] == x {
                x
            } else {
                self.0[i] = self.getp(self.0[i]);
                self.0[i]
            }
        }
    }
 
    pub fn setp(&mut self, x: i32, y: i32) -> Result<(i32, i32), bool> {
        let x = self.getp(x);
        let y = self.getp(y);
        if x == y {
            Err(true)
        } else if x == !y {
            Err(false)
        } else {
            let (x, y) = if x >= 0 { (x, y) } else { (!x, !y) };
            self.0[x as usize] = y;
            Ok((x, y))
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
    const DIR: [&str; 2] = ["R", "L"];
    let [n, m]: [usize; 2] = read_vec::<usize>().try_into().unwrap();
    let mut ds = ExtDisjointSet::new(n);
    let mut v = Vec::with_capacity(m);
    let mut ok = true;
    for _ in 0..m {
        if let [t, mut i, mut j] = read_vec::<usize>()[..] {
            i -= 1;
            j -= 1;
            if ds.setp(i as i32, !(j as i32)) == Err(false) {
                ok = false;
                break;
            }
            v.push((t, i, j));
        }
    }
 
    let mut d = vec![0; n];
    let mut e = vec![vec![]; n];
    for (t, i, j) in v {
        if (t == 1) == (ds.getp(i as i32) >= 0) {
            d[j] += 1;
            e[i].push(j);
        } else {
            d[i] += 1;
            e[j].push(i);
        }
    }
 
    let mut x = 0;
    let mut q = d
        .iter()
        .enumerate()
        .filter_map(|(i, j)| if j == &0 { Some(i) } else { None })
        .collect::<Vec<_>>();
    let mut ans = vec![String::new(); n];
    while let Some(i) = q.pop() {
        x += 1;
        ans[i] = format!("{} {}", DIR[(ds.getp(i as i32) >= 0) as usize], x);
        for &j in &e[i] {
            d[j] -= 1;
            if d[j] == 0 {
                q.push(j);
            }
        }
    }
    ok &= x == n;
    if ok {
        println!("YES\n{}", ans.join("\n"));
    } else {
        println!("NO");
    }
}

// 150561083	Mar/22/2022 18:37UTC-7	watashi	1635E - Cars	Rust 2021	Accepted	186 ms	28900 KB
