impl Solution {
    pub fn count_rectangles(rectangles: Vec<Vec<i32>>, points: Vec<Vec<i32>>) -> Vec<i32> {
        let mut xs = vec![vec![]; 101];
        for rect in rectangles {
            for x in 1..=rect[1] as usize {
                xs[x].push(rect[0]);
            }
        }
        for x in &mut xs {
            x.sort_unstable();
        }
        points.iter().map(|p| {
            use std::cmp::Ordering::*;
            let x = &xs[p[1] as usize];
            let idx = x.binary_search_by(|&i| if i >= p[0] { Greater } else { Less });
            (x.len() - idx.unwrap_err()) as i32
        }).collect()
    }
}
