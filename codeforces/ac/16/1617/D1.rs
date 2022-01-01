use std::*;

fn readln() -> usize {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse().unwrap()
}

fn query(a: usize, b: usize, c: usize) -> usize {
    println!("? {} {} {}", a, b, c);
    readln()
}

fn solve_one(player: &mut [Vec<usize>; 2], p: usize) -> usize {
    let q = query(player[0][0], player[1][0], p);
    eprintln!("solve_one({}) = {}", p, q);
    player[q].push(p);
    q
}

fn sovle_diff(player: &mut [Vec<usize>; 2], g0: usize, g1: usize) {
    eprintln!("solve_diff({}, {})", g0, g1);
    let q1 = query(g0 + 1, g0 + 2, g1 + 1);
    let q2 = query(g0 + 1, g0 + 2, g1 + 2);
    if q1 == 0 && q2 == 0 {
        player[0].push(g0 + 1);
        player[0].push(g0 + 2);
        let qs = [(2, 3), (1, 3), (1, 2)].map(|(i, j)| query(g0 + 1, g1 + i, g1 + j));
        if qs.iter().all(|&q| q == 1) {
            player[1].extend([g1 + 1, g1 + 2, g1 + 3]);
        } else {
            for i in 0..3 {
                player[1 - qs[i]].push(g1 + 1 + i);
            }
        }
        solve_one(player, g0 + 3);
    } else {
        player[0].push(g0 + 3);
        player[q1].push(g1 + 1);
        player[q2].push(g1 + 2);
        solve_one(player, g1 + 3);
        solve_one(player, g0 + 1);
        solve_one(player, g0 + 2);
    }
}

fn main() {
    let re = readln();
    for _ in 0..re {
        let n = readln();
        let mut group = [vec![], vec![]];
        for i in (0..n).step_by(3) {
            group[query(i + 1, i + 2, i + 3)].push(i);
        }
        let mut player = [vec![], vec![]];
        if let (Some(g0), Some(g1)) = (group[0].pop(), group[1].pop()) {
            sovle_diff(&mut player, g0, g1);
        }
        for q in 0..2 {
            while let Some(g) = group[q].pop() {
                for i in [1, 2, 3] {
                    solve_one(&mut player, g + i);
                }
            }
        }
        let ans = player[0].iter().map(|i| i.to_string()).collect::<Vec<_>>();
        println!("! {} {}", ans.len(), ans[..].join(" "));
    }
}

// 140973906	Dec/28/2021 18:00UTC-8	watashi	1617D1 - Too Many Impostors (easy version)	Rust 2021	Happy New Year!	920 ms	400 KB
