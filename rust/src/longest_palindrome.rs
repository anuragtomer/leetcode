impl Solution {
    #[allow(dead_code)]
    pub fn longest_palindrome(s: String) -> i32 {
        let mut length: i32 = 0;
        let mut count_vec: Vec<i32> = vec![0; 128];
        for &ch in s.as_bytes() {
            count_vec[ch as usize] += 1;
        }
        for count in count_vec.iter() {
            length += count;
            if count % 2 == 1 && length % 2 == 0 {
                // current chars count is odd, but after adding it to length, the length of the string is even
                // So we might have added an odd count character earlier too.
                length -= 1;
            }
        }
        length
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_longest_palindrome() {
        assert_eq!(Solution::longest_palindrome("abccccdd".to_string()), 7);
        assert_eq!(Solution::longest_palindrome("a".to_string()), 1);
    }
}
