impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        use std::cmp::Ordering;
        let (mut low, mut high) = (0, nums.len());
        while low < high {
            let mid = low + (high - low) / 2;
            match nums[mid].cmp(&target) {
                Ordering::Equal => return mid as i32,
                Ordering::Less => low = mid + 1,
                Ordering::Greater => high = mid,
            }
        }
        -1
    }
}
pub struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_is_anagram() {
        assert_eq!(Solution::search(vec![-1, 0, 3, 5, 9, 12], 9), 4);
        assert_eq!(Solution::search(vec![-1, 0, 3, 5, 9, 12], 2), -1);
    }
}
