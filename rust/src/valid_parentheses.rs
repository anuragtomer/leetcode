impl Solution {
    #[allow(dead_code)]
    pub fn is_valid(s: String) -> bool {
        let mut st = vec![];
        for ch in s.chars() {
            match ch {
                '(' | '[' | '{' => st.push(ch),
                ')' => {
                    if st.pop() != Some('(') {
                        return false;
                    }
                }
                ']' => {
                    if st.pop() != Some('[') {
                        return false;
                    }
                }
                '}' => {
                    if st.pop() != Some('{') {
                        return false;
                    }
                }
                _ => return false,
            }
        }
        st.is_empty()
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {
    use crate::valid_parentheses::Solution;

    #[test]
    fn test_1() {
        assert_eq!(Solution::is_valid("()".to_string()), true);
        assert_eq!(Solution::is_valid("()[]{}".to_string()), true);
        assert_eq!(Solution::is_valid("(]".to_string()), false);
    }
}
