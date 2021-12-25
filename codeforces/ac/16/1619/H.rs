use std::{io::*, iter::*};

fn read_line() -> String {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

const BLOCK_BITS: usize = 8;
const BLOCK_SIZE: usize = 1 << BLOCK_BITS;

fn update(next_block: &mut Vec<usize>, next: &Vec<usize>, prev: &Vec<usize>, x: usize) {
    let mut chain: Vec<usize> = successors(Some(x), |&i| Some(prev[i]))
        .skip(1)
        .take(BLOCK_SIZE)
        .collect();
    chain.reverse();
    chain.extend(successors(Some(x), |&i| Some(next[i])).take(BLOCK_SIZE + 1));
    for i in 0..=BLOCK_SIZE {
        next_block[chain[i]] = chain[i + BLOCK_SIZE];
    }
}

fn main() {
    let nq = read_vec::<usize>();
    let (n, q) = (nq[0], nq[1]);
    let mut next = vec![0; n];
    let mut prev = vec![0; n];
    for (i, &j) in read_vec::<usize>().iter().enumerate() {
        next[i] = j - 1;
        prev[j - 1] = i;
    }

    let mut next_block = next.clone();
    for _ in 0..BLOCK_BITS {
        next_block = (0..n).map(|i| next_block[next_block[i]]).collect()
    }

    let mut ans = vec![];
    for _ in 0..q {
        match read_vec::<usize>()[..] {
            [1, x, y] => {
                let (x, y) = (x - 1, y - 1);
                let (xx, yy) = (next[x], next[y]);
                next[x] = yy;
                next[y] = xx;
                prev[yy] = x;
                prev[xx] = y;
                update(&mut next_block, &next, &prev, x);
                update(&mut next_block, &next, &prev, y);
            }
            [2, mut x, mut y] => {
                x -= 1;
                for _ in 0..y / BLOCK_SIZE {
                    x = next_block[x];
                }
                for _ in 0..y % BLOCK_SIZE {
                    x = next[x];
                }
                ans.push((x + 1).to_string());
            }
            _ => {}
        }
    }
    println!("{}", ans.join("\n"));
}

// 140547183	Dec/24/2021 22:37UTC-8	watashi	1619H - Permutation and Queries	Rust 2021	Happy New Year!	1575 ms	8500 KB
