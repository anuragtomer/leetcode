impl Solution {
    #[allow(dead_code)]
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let (mut major_element, mut major_count) = (0, 0);
        for (i, num) in nums.iter().enumerate() {
            if i == 0 {
                major_count = 1;
                major_element = *num;
            } else if nums[i] == major_element {
                major_count += 1;
            } else {
                major_count -= 1;
                if major_count < 0 {
                    major_count = 1;
                    major_element = *num;
                }
            }
        }
        major_element
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_majority_element() {
        assert_eq!(Solution::majority_element(vec![3, 2, 3]), 3);
        assert_eq!(Solution::majority_element(vec![2, 2, 1, 1, 1, 2, 2]), 2);
        assert_eq!(
            Solution::majority_element(vec![2, 2, 1, 1, 1, 2, 2, 1, 1]),
            1
        );
    }
}
