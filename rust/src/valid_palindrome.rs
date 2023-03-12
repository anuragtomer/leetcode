impl Solution {
    #[allow(dead_code)]
    pub fn is_palindrome(s: String) -> bool {
        let refined = s
            .chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase());
        refined.clone().eq(refined.rev())
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_valid_palindrome() {
        assert!(Solution::is_palindrome(String::from(
            "A man, a plan, a canal: Panama"
        )));
        assert!(!Solution::is_palindrome(String::from("race a car")));
        assert!(Solution::is_palindrome(String::from(" ")));
    }
}
