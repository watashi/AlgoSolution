pub mod splay {
    use std::{fmt::*, *};

    pub struct Splay<T> {
        root: Option<Box<Node<T>>>,
    }

    pub struct Node<T> {
        len: usize,
        value: T,
        parent: *mut Self,
        left: Splay<T>,
        right: Splay<T>,
    }

    fn fmt_impl<T: Debug>(splay: &Splay<T>, f: &mut Formatter, indent: usize) -> Result {
        if let Some(root) = splay.get_root() {
            fmt_impl(&root.right, f, indent + 2)?;
            writeln!(
                f,
                "{:indent$}{:?} [{}] @ {:?} ^ {:?}",
                "",
                root.value(),
                root.len,
                root as *const Node<T>,
                root.parent,
                indent = indent
            )?;
            fmt_impl(&root.left, f, indent + 2)?;
        }
        Ok(())
    }

    impl<T: Debug> Debug for Splay<T> {
        fn fmt(&self, f: &mut Formatter) -> Result {
            fmt_impl(&self, f, 0)
        }
    }

    impl<T> From<Box<Node<T>>> for Splay<T> {
        fn from(root: Box<Node<T>>) -> Splay<T> {
            Splay { root: Some(root) }
        }
    }

    impl<T> Splay<T> {
        pub fn empty() -> Self {
            Splay { root: None }
        }

        pub fn singleton(value: T) -> Self {
            let root = Node {
                len: 1,
                value: value,
                parent: ptr::null_mut(),
                left: Self::empty(),
                right: Self::empty(),
            };
            Box::new(root).into()
        }

        pub fn len(&self) -> usize {
            self.root.as_deref().map_or(0, |x| x.len)
        }

        pub fn get_root(&self) -> Option<&Node<T>> {
            self.root.as_deref()
        }

        fn get_root_unwrap(&self) -> &Node<T> {
            self.root.as_deref().unwrap()
        }

        fn get_root_unwrap_mut(&mut self) -> &mut Node<T> {
            self.root.as_deref_mut().unwrap()
        }

        fn set_parent(&mut self, parent: *mut Node<T>) {
            self.root.as_mut().map(|x| x.parent = parent);
        }

        fn detach(&mut self, subtree: &Node<T>) -> Self {
            match subtree.get_parent() {
                Some(p) => {
                    if p.has_left_child(subtree) {
                        mem::replace(&mut p.left, Self::empty())
                    } else {
                        mem::replace(&mut p.right, Self::empty())
                    }
                }
                None => mem::replace(self, Self::empty()),
            }
        }

        fn zig_or_zag(&mut self, parent: &Node<T>, child: &Node<T>) {
            let zig = parent.has_left_child(&child);
            let grandparent = parent.get_parent();
            let attach_to_left = grandparent.as_ref().map(|i| i.has_left_child(&parent));
            let grandchild = if zig { &child.right } else { &child.left };
            let grandchild = grandchild
                .get_root()
                .map_or(Self::empty(), |i| self.detach(i));
            let mut child = self.detach(child).root.unwrap();
            let mut parent = self.detach(parent).root.unwrap();
            if zig {
                parent.set_left(grandchild);
                child.set_right(parent.into());
            } else {
                parent.set_right(grandchild);
                child.set_left(parent.into());
            }
            match attach_to_left {
                None => {
                    *self = child.into();
                    self.set_parent(ptr::null_mut());
                }
                Some(true) => grandparent.unwrap().set_left(child.into()),
                Some(false) => grandparent.unwrap().set_right(child.into()),
            }
        }

        pub(crate) fn splay(&mut self, node: *const Node<T>) {
            let node = unsafe { node.as_ref().unwrap() };
            while let Some(p) = node.get_parent() {
                if let Some(g) = p.get_parent() {
                    if g.has_left_child(p) == p.has_left_child(node) {
                        self.zig_or_zag(g, p);
                        self.zig_or_zag(p, node);
                    } else {
                        self.zig_or_zag(p, node);
                        self.zig_or_zag(g, node);
                    }
                } else {
                    self.zig_or_zag(p, node);
                }
            }
        }

        pub fn get_nth(&mut self, n: usize) -> Option<&Node<T>> {
            if n >= self.len() {
                None
            } else {
                let node: *const _ = self.get_root_unwrap().get_nth(n);
                self.splay(node);
                Some(self.get_root_unwrap())
            }
        }

        pub fn get_rank(&mut self, node: *const Node<T>) -> usize {
            self.splay(node);
            self.get_root_unwrap().get_left().len()
        }

        pub fn concat_back(&mut self, other: &mut Self) {
            match self.get_root() {
                None => {
                    mem::swap(self, other);
                }
                Some(mut node) => {
                    while let Some(child) = node.right.get_root() {
                        node = child;
                    }
                    let node: *const _ = node;
                    self.splay(node);
                    self.get_root_unwrap_mut()
                        .set_right(mem::replace(other, Splay::empty()));
                }
            };
        }

        pub fn drop_until_exclusive(&mut self, node: *const Node<T>) -> Splay<T> {
            self.splay(node);
            let root = self.get_root_unwrap_mut();
            let mut prefix = mem::replace(&mut root.left, Splay::empty());
            root.fix_node();
            if let Some(p) = prefix.root.as_deref_mut() {
                p.parent = ptr::null_mut();
            }
            prefix
        }

        // rotate such that node is the first element
        pub fn rotate(&mut self, node: *const Node<T>) {
            let mut prefix = self.drop_until_exclusive(node);
            self.concat_back(&mut prefix);
        }
    }

    impl<T> Node<T> {
        fn get_parent(&self) -> Option<&mut Self> {
            unsafe { self.parent.as_mut() }
        }

        fn has_left_child(&self, child: &Self) -> bool {
            match self.left.root.as_deref() {
                Some(left) => ptr::eq(left, child),
                None => false,
            }
        }

        fn fix_node(&mut self) {
            self.len = 1 + &self.left.len() + &self.right.len();
        }

        fn get_nth(&self, n: usize) -> &Self {
            let left = self.left.len();
            if n < left {
                self.left.get_root_unwrap().get_nth(n)
            } else if n == left {
                self
            } else {
                self.right.get_root_unwrap().get_nth(n - left - 1)
            }
        }

        pub fn set_left(&mut self, left: Splay<T>) {
            self.left = left;
            let p: *mut Node<T> = self;
            self.left.set_parent(p);
            self.fix_node();
        }

        pub fn set_right(&mut self, right: Splay<T>) {
            self.right = right;
            let p: *mut Node<T> = self;
            self.right.set_parent(p);
            self.fix_node();
        }

        pub fn value(&self) -> &T {
            &self.value
        }

        pub fn get_left(&self) -> &Splay<T> {
            &self.left
        }

        pub fn get_right(&self) -> &Splay<T> {
            &self.right
        }

        // this can be slow when not being followed by a splay operation
        pub fn get_root(&self) -> &Self {
            let mut root = self;
            while let Some(parent) = root.get_parent() {
                root = parent;
            }
            root
        }
    }
}

use splay::*;
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

fn load(seq: &mut Vec<Splay<usize>>, node: *const Node<usize>) -> Splay<usize> {
    let &root = unsafe { node.as_ref() }.unwrap().get_root().value();
    let mut splay = mem::replace(&mut seq[root], Splay::empty());
    if splay.len() > 0 {
        splay.splay(node);
    }
    // println!("loading:\n{:?}", &splay);
    splay
}

fn store(seq: &mut Vec<Splay<usize>>, splay: Splay<usize>) {
    if let Some(root) = splay.get_root() {
        // println!("storeing:\n{:?}", &splay);
        let &root = root.value();
        seq[root] = splay;
    }
}

fn main() {
    let nq = read_vec::<usize>();
    let (n, q) = (nq[0], nq[1]);

    let mut seq = (0..n).map(|i| Splay::singleton(i)).collect::<Vec<_>>();
    let node = seq
        .iter()
        .map(|i| i.get_root().unwrap() as *const Node<usize>)
        .collect::<Vec<_>>();
    let mut p = read_vec::<usize>()
        .iter()
        .map(|i| i - 1)
        .collect::<Vec<_>>();
    for i in 0..n {
        if seq[i].len() != 1 {
            continue;
        }
        let mut group = load(&mut seq, node[i]);
        let mut j = p[i];
        while j != i {
            group.concat_back(&mut seq[j]);
            j = p[j];
        }
        store(&mut seq, group);
    }

    let mut ans = vec![];
    for _ in 0..q {
        match read_vec::<usize>()[..] {
            [1, x, y] => {
                let (x, y) = (x - 1, y - 1);
                let (px, py) = (p[x], p[y]);
                // println!("{:?}", p);
                p[x] = py;
                p[y] = px;
                // println!("{:?}", p);
                let mut groupx = load(&mut seq, node[x]);
                groupx.rotate(node[px]);
                let mut groupy = load(&mut seq, node[y]);
                if groupy.len() == 0 {
                    // x and y are in the same group
                    groupy = groupx.drop_until_exclusive(node[py]);
                    store(&mut seq, groupx);
                    store(&mut seq, groupy);
                } else {
                    groupy.rotate(node[py]);
                    groupx.concat_back(&mut groupy);
                    store(&mut seq, groupx);
                }
            }
            [2, mut x, mut y] => {
                x -= 1;
                /*
                let mut zz = x;
                for _ in 0..y {
                    zz = p[zz];
                }
                */
                let mut group = load(&mut seq, node[x]);
                y += group.get_rank(node[x]);
                y %= group.len();
                let z = *group.get_nth(y).unwrap().value();
                store(&mut seq, group);
                ans.push((z + 1).to_string());
            }
            _ => {}
        }
    }
    println!("{}", ans.join("\n"));
}

// 140842859	Dec/27/2021 13:17UTC-8	watashi	1619H - Permutation and Queries	Rust 2021	Happy New Year!	451 ms	13300 KB
