impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut max_wealth: i32 = 0;
        for i in 0..accounts.len() {
            let mut curr_wealth: i32 = 0;
            for j in 0..accounts[i].len() {
                curr_wealth += accounts[i][j];
            }
            if max_wealth < curr_wealth {
                max_wealth = curr_wealth;
            }
        }
        max_wealth
    }
}
struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_maximum_wealth() {
        assert_eq!(
            Solution::maximum_wealth(vec![vec![1, 2, 3], vec![3, 2, 1]]),
            6
        );
        assert_eq!(
            Solution::maximum_wealth(vec![vec![1, 5], vec![7, 3], vec![3, 5]]),
            10
        );
        assert_eq!(
            Solution::maximum_wealth(vec![vec![2, 8, 7], vec![7, 1, 3], vec![1, 9, 5]]),
            17
        );
    }
}
