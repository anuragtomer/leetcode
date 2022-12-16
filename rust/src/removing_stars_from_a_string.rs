impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut result: String = "".to_string();
        for ch in s.chars() {
            if ch == '*' {
                result.pop();
            } else {
                result.push(ch);
            }
        }
        result
    }
}
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_remove_stars() {
        assert_eq!(Solution::remove_stars(String::from("leet**cod*e")), "lecoe");
        assert_eq!(Solution::remove_stars(String::from("erase*****")), "");
    }
}
