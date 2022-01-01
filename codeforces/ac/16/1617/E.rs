use std::{collections::*, io::*, *};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

struct Trie<K, V> {
    label: Option<V>,
    forest: HashMap<K, Self>,
}

impl<K: Copy + Eq + hash::Hash, V> Trie<K, V> {
    fn new() -> Self {
        Trie {
            label: None,
            forest: HashMap::new(),
        }
    }

    fn insert_one(&mut self, k: K) -> &mut Self {
        if !self.forest.contains_key(&k) {
            self.forest.insert(k, Trie::new());
        }
        self.forest.get_mut(&k).unwrap()
    }

    fn insert(&mut self, ks: impl Iterator<Item = K>) -> &mut Self {
        let mut t = self;
        for k in ks {
            t = t.insert_one(k);
        }
        t
    }
}

fn gao<K, V: Default>(t: &Trie<K, V>) -> (Option<(u32, &V, &V)>, (u32, &V)) {
    let (mut x, mut y) = (vec![], vec![]);
    for (_, i) in &t.forest {
        let (xi, mut yi) = gao(i);
        if let Some(xi) = xi {
            x.push(xi);
        }
        yi.0 += 1;
        y.push(yi);
    }
    if let Some(s) = &t.label {
        y.push((0, s));
    }
    if y.len() > 1 {
        let cmp = |i: &(u32, _), j: &(u32, _)| j.0.cmp(&i.0);
        y.select_nth_unstable_by(1, cmp);
        y.truncate(2);
        y.sort_unstable_by(cmp);
        x.push((y[0].0 + y[1].0, y[0].1, y[1].1));
    }
    let x = x.into_iter().reduce(|i, j| if i.0 > j.0 { i } else { j });
    (x, y[0])
}

fn main() {
    read_line();
    let mut t: Trie<u32, usize> = Trie::new();
    for (i, &x) in read_vec::<u32>().iter().enumerate() {
        let mut x = x;
        let mut v = vec![];
        while x > 0 {
            v.push(x);
            if x.count_ones() == 1 {
                break;
            } else {
                let z = x.leading_zeros();
                x = (!x << z >> z) + 1;
            }
        }
        // println!("{:?}", v);
        t.insert(v.iter().rev().copied()).label = Some(i);
    }
    if let Some((d, x, y)) = gao(&t).0 {
        println!("{} {} {}", x + 1, y + 1, d);
    }
}

// 141207491	Dec/30/2021 18:33UTC-8	watashi	1617E - Christmas Chocolates	Rust 2021	Happy New Year!	982 ms	373900 KB
