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

fn tick_one(xs: Vec<i64>, ys: &Vec<i64>) -> (Vec<usize>, Vec<i64>) {
    let mut it = ys.iter().copied().zip(xs).peekable();
    let mut groups = vec![];
    while let Some((_, mut xx)) = it.peek() {
        let (mut gl, mut gz, mut gr) = (vec![], vec![], vec![]);
        let (mut sl, mut sr) = (0, 0);
        while let Some(&(y, x)) = it.peek() {
            if x != xx {
                break;
            }
            xx += 1;
            it.next();
            gr.push(x);
            sr += y;
            if sr < 0 {
                gl.extend(gz);
                gl.extend(gr);
                gz = vec![];
                gr = vec![];
                sl += sr;
                sr = 0;
            } else if sr == 0 {
                gz.extend(gr);
                gr = vec![];
            }
        }
        for (s, g) in [(sl, gl), (0, gz), (sr, gr)] {
            if !g.is_empty() {
                groups.push((s, g));
            }
        }
    }

    let mut separated = vec![];
    let mut c = 0;
    for i in 1..groups.len() {
        let (sl, gl) = &groups[i - 1];
        let (sr, gr) = &groups[i];
        c += gl.len();
        if sl > &0 && sr < &0 && gr.first().unwrap() - gl.last().unwrap() == 2 {
            if sl.abs() <= sr.abs() {
                groups[i - 1].0 = 0;
            } else {
                groups[i].0 = 0;
            }
        } else {
            separated.push(c - 1);
        }
    }

    let xs = groups
        .into_iter()
        .flat_map(|(s, g)| g.into_iter().map(move |i| i + s.signum()))
        .collect();
    (separated, xs)
}

fn tick_cycle(mut xs: Vec<i64>, y: &Vec<Vec<i64>>) -> (u64, Vec<Vec<i64>>) {
    let n = xs.len();
    let m = y.len();
    let mut v = vec![xs.clone()];
    'cycle: loop {
        let mut sep = vec![0; n - 1];
        for i in 0..m {
            let ret = tick_one(xs, &y[i]);
            for j in ret.0 {
                sep[j] += 1;
            }
            xs = ret.1;
            v.push(xs.clone());
        }

        let gaps = v[v.len() - m - 1..]
            .iter()
            .map(|vi| vi.iter().skip(1).zip(vi).map(|(i, j)| i - j).collect())
            .collect::<Vec<Vec<_>>>();
        let diff = gaps[m]
            .iter()
            .zip(&gaps[0])
            .map(|(i, j)| i - j)
            .collect::<Vec<_>>();
        let mingap = gaps[1..m].into_iter().fold(gaps[0].clone(), |mut a, b| {
            for (i, j) in a.iter_mut().zip(b) {
                *i = cmp::min(*i, *j);
            }
            a
        });
        /*
        println!("sep:    {:?}", sep);
        println!("diff:   {:?}", diff);
        println!("mingap: {:?}", mingap);
        */

        let mut next = u64::MAX;
        for i in 0..n - 1 {
            if diff[i] == 0 {
                continue;
            }
            if sep[i] != m {
                continue 'cycle;
            }
            if diff[i] < 0 {
                next = cmp::min(next, ((mingap[i] - 1) / -diff[i]) as u64);
            }
        }
        if next > 1 {
            return (next, v);
        }
    }
}

fn query(m: usize, v: &Vec<Vec<i64>>, mut t: u64) -> Vec<i64> {
    let n = v.len();
    if t < n as u64 {
        v[t as usize].clone()
    } else {
        t -= n as u64;
        let q = (t / m as u64) as i64;
        let r = (t % m as u64) as usize;
        v[n - m + r]
            .iter()
            .zip(&v[n - 1])
            .zip(&v[n - 1 - m])
            .map(|((i, j), k)| i + (j - k) * (q + 1))
            .collect()
    }
}

fn main() {
    let nm = read_vec::<usize>();
    let (n, m) = (nm[0], nm[1]);
    let mut x = read_vec::<i64>();
    let mut y = vec![vec![]; m];
    for _ in 0..n {
        for (i, f) in read_vec::<i64>().into_iter().enumerate() {
            y[i].push(f);
        }
    }
    let y = y;

    let mut key_points = vec![];
    let mut now = 0;
    loop {
        let (next, v) = tick_cycle(x, &y);
        // println!("====\n{:?}\nnext = {}", v, next);
        if next == u64::MAX {
            key_points.push((now, v));
            break;
        }
        let next = (next - 1) * m as u64 + v.len() as u64 - 1;
        x = query(m, &v, next);
        key_points.push((now, v));
        now += next;
    }
    let key_points = key_points;
    /*
    for (s, v) in &key_points {
        println!("@{}: {:?}", s, v);
    }
    */

    let q = read_vec::<usize>()[0];
    for _ in 0..q {
        if let [k, t] = read_vec::<u64>()[..] {
            let key_index = key_points
                .binary_search_by(|i| i.0.cmp(&t))
                .unwrap_or_else(|i| i - 1);
            let (s, v) = &key_points[key_index];
            println!("{}", query(m, v, t - s)[k as usize - 1]);
        }
    }
}

// 142903193	Jan/15/2022 15:26UTC-8	watashi	1609H - Pushing Robots	Rust 2021	Accepted	187 ms	14400 KB
