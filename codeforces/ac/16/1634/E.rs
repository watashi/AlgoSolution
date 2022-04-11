use std::{collections::*, *};

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

fn pop<T: Clone + Eq + hash::Hash>(hs: &mut HashSet<T>) -> Option<T> {
    hs.iter().cloned().next().and_then(|x| hs.take(&x))
}

fn main() {
    let m: usize = read_line().trim().parse().unwrap();
    let mut ans = Vec::with_capacity(m);
    let mut byv = HashMap::<i32, HashSet<(usize, usize)>>::new();
    let mut byr = Vec::with_capacity(m);
    for i in 0..m {
        read_line();
        let a = read_vec::<i32>();
        ans.push(vec![b'?'; a.len()]);
        for (j, &k) in a.iter().enumerate() {
            byv.entry(k).or_default().insert((i, j));
        }
        byr.push(a.into_iter().enumerate().collect::<HashSet<_>>());
    }

    if byv.values().any(|i| i.len() % 2 != 0) {
        println!("NO");
    } else {
        for i in 0..m {
            while let Some((j, k)) = pop(&mut byr[i]) {
                byv.get_mut(&k).unwrap().remove(&(i, j));
                ans[i][j] = b'L';
                let mut ii = i;
                loop {
                    let (jj, kk) = pop(&mut byr[ii]).unwrap();
                    let todo = byv.get_mut(&kk).unwrap();
                    todo.remove(&(ii, jj));
                    ans[ii][jj] = b'R';
                    if kk == k {
                        break;
                    }
                    let (iii, jjj) = pop(todo).unwrap();
                    byr[iii].remove(&(jjj, kk));
                    ans[iii][jjj] = b'L';
                    ii = iii;
                }
            }
        }
        let ans = ans
            .into_iter()
            .map(|i| String::from_utf8(i).unwrap())
            .collect::<Vec<_>>();
        println!("YES\n{}", ans.join("\n"));
    }
}

// 150303125	Mar/20/2022 13:29UTC-7	watashi	1634E - Fair Share	Rust 2021	Accepted	1356 ms	52000 KB
