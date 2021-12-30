use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_pair() -> (usize, usize) {
    let x: Vec<usize> = read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect();
    (x[0], x[1])
}

type Tree = Vec<(Option<usize>, Option<usize>)>;

fn inorder(tree: &Tree, root: Option<usize>, result: &mut Vec<usize>) {
    if let Some(root) = root {
        inorder(tree, tree[root].0, result);
        result.push(root);
        inorder(tree, tree[root].1, result);
    }
}

fn dup(
    tree: &Tree,
    next: &Vec<bool>,
    root: Option<usize>,
    depth: usize,
    rest: &mut usize,
    ret: &mut Vec<usize>,
) -> bool {
    match root {
        Some(root) if depth <= *rest => {
            let mut f = dup(tree, next, tree[root].0, depth + 1, rest, ret);
            if !f && next[root] {
                *rest -= depth;
                f = true;
            }
            if f {
                ret.push(root);
                dup(tree, next, tree[root].1, 1, rest, ret);
            }
            f
        }
        _ => false,
    }
}

fn main() {
    let (n, mut k) = read_pair();
    let s = read_line();
    let s = s.trim().chars().collect::<Vec<_>>();
    let tree = (0..n)
        .map(|_| {
            let (l, r) = read_pair();
            (l.checked_sub(1), r.checked_sub(1))
        })
        .collect::<Tree>();

    let mut x = Vec::with_capacity(n);
    inorder(&tree, Some(0), &mut x);
    let (mut pre1, mut pre2) = ('\0', '\0');
    let mut next = vec![false; n];
    for i in (0..n).rev() {
        if s[x[i]] != pre1 {
            pre2 = pre1;
            pre1 = s[x[i]];
        }
        next[x[i]] = s[x[i]] < pre2;
    }
    let mut y = vec![];
    dup(&tree, &next, Some(0), 1, &mut k, &mut y);

    let mut it = y.into_iter().peekable();
    let mut ans = String::new();
    for i in x {
        if it.peek() == Some(&i) {
            it.next();
            ans.push(s[i]);
        }
        ans.push(s[i]);
    }
    println!("{}", ans);
}

// 141136570	Dec/30/2021 00:25UTC-8	watashi	1623E - Middle Duplication	Rust 2021	Happy New Year!	139 ms	44600 KB
