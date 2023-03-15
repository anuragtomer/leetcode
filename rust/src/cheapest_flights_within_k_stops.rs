impl Solution {
    #[allow(dead_code)]
    pub fn find_cheapest_price(n: i32, flights: Vec<Vec<i32>>, src: i32, dst: i32, k: i32) -> i32 {
        let (n, src, dst, k) = (n as usize, src as usize, dst as usize, k as usize);

        let mut cost = vec![i32::MAX; n];
        cost[src] = 0;
        for _i in 0..=k {
            let mut temp_cost = cost.clone();
            for flight in flights.iter() {
                if cost[flight[0] as usize] < i32::MAX - flight[2] {
                    temp_cost[flight[1] as usize] = std::cmp::min(
                        temp_cost[flight[1] as usize],
                        cost[flight[0] as usize] + flight[2],
                    );
                }
            }
            cost = temp_cost.clone();
        }
        match cost[dst] == i32::MAX {
            true => -1,
            false => cost[dst],
        }
    }
}
pub struct Solution {}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_cheapest_flights_within_k_stops() {
        assert_eq!(
            Solution::find_cheapest_price(
                3,
                vec![vec![0, 1, 100], vec![1, 2, 100], vec![0, 2, 500]],
                0,
                2,
                1
            ),
            200
        );
        assert_eq!(
            Solution::find_cheapest_price(
                3,
                vec![vec![0, 1, 100], vec![1, 2, 100], vec![0, 2, 500]],
                0,
                2,
                0
            ),
            500
        );
        assert_eq!(
            Solution::find_cheapest_price(
                4,
                vec![
                    vec![0, 1, 100],
                    vec![1, 2, 100],
                    vec![2, 0, 100],
                    vec![1, 3, 600],
                    vec![2, 3, 200]
                ],
                0,
                3,
                1
            ),
            700
        );
    }
}
