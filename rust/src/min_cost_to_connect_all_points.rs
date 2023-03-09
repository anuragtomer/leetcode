use std::cmp::{Ordering, Reverse};
use std::collections::{BinaryHeap, HashSet};

impl Solution {
    pub fn min_cost_connect_points(points: Vec<Vec<i32>>) -> i32 {
        #[derive(Eq)]
        struct DistanceMap {
            cost: usize,
            source: usize,
            destination: usize,
        }

        impl Ord for DistanceMap {
            fn cmp(&self, other: &Self) -> Ordering {
                self.cost.cmp(&other.cost)
            }
        }
        impl PartialOrd for DistanceMap {
            fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
                Some(self.cmp(other))
            }
        }

        impl PartialEq for DistanceMap {
            fn eq(&self, other: &Self) -> bool {
                self.cost == other.cost
            }
        }
        let n = points.len();
        if n <= 1 {
            // If there are no points or there is just 1 point, the cost is 0.
            return 0;
        }
        let mut cost: i32 = 0;
        let mut edge_cost: Vec<Vec<usize>> = vec![vec![<usize>::MAX; points.len()]; points.len()];
        for i in 0..points.len() {
            for j in i + 1..points.len() {
                let distance =
                    (points[i][0] - points[j][0]).abs() + (points[i][1] - points[j][1]).abs();
                edge_cost[i][j] = distance as usize;
                edge_cost[j][i] = distance as usize;
            }
        }
        let mut chosen_vertices = HashSet::new();
        chosen_vertices.insert(0);
        let mut pq = BinaryHeap::new();
        for j in 1..n {
            pq.push(Reverse(DistanceMap {
                cost: edge_cost[0][j],
                source: 0,
                destination: j,
            }));
        }
        let mut cost = 0;
        while !pq.is_empty() && chosen_vertices.len() < points.len() {
            let tp = pq.pop().unwrap().0;
            if chosen_vertices.contains(&tp.source) && chosen_vertices.contains(&tp.destination) {
                // Both vertices are already part of chosen set. Find next closest
                // point.
                continue;
            }
            cost += tp.cost;
            let mut new_vertex = tp.source;
            if chosen_vertices.contains(&tp.source) {
                new_vertex = tp.destination;
                chosen_vertices.insert(tp.destination);
            } else {
                new_vertex = tp.source;
                chosen_vertices.insert(tp.source);
            }

            for j in 0..n {
                // put all neighboring nodes of this new node.
                pq.push(Reverse(DistanceMap {
                    cost: edge_cost[new_vertex][j],
                    source: new_vertex,
                    destination: j,
                }));
            }
        }
        if chosen_vertices.len() == n {
            return cost as i32;
        }
        return -1;
    }
}

struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_min_cost_to_connect_all_points_1() {
        assert_eq!(
            20,
            Solution::min_cost_connect_points(vec![
                vec![0, 0],
                vec![2, 2],
                vec![3, 10],
                vec![5, 2],
                vec![7, 0]
            ])
        );
        assert_eq!(
            18,
            Solution::min_cost_connect_points(vec![vec![3, 12], vec![-2, 5], vec![-4, 1]])
        );
    }
}
