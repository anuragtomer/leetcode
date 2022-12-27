use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash = HashMap::with_capacity(nums.len());
        for (i, &num) in nums.iter().enumerate() {
            let y = target - num;
            if let Some(&idx) = hash.get(&y) {
                return vec![i as i32, idx as i32];
            } else {
                hash.insert(num, i);
            }
        }
        vec![]
    }
}
struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let mut res = Solution::two_sum(vec![2, 7, 11, 15], 9);
        res.sort();
        assert_eq!(vec![0, 1], res);
        res = Solution::two_sum(vec![3, 2, 4], 6);
        res.sort();
        assert_eq!(vec![1, 2], res);
    }
}
