impl Solution {
    #[allow(dead_code)]
    pub fn add_binary(a: String, b: String) -> String {
        let (mut carry, mut i, mut j): (i32, i32, i32) =
            (0, a.len() as i32 - 1, b.len() as i32 - 1);
        let mut result: String = String::new();
        while (carry > 0) || (i >= 0) || (j >= 0) {
            carry = carry
                + (if i >= 0 && a.chars().nth(i as usize) == Some('1') {
                    1
                } else {
                    0
                })
                + (if j >= 0 && b.chars().nth(j as usize) == Some('1') {
                    1
                } else {
                    0
                });
            i -= 1;
            j -= 1;
            if (carry % 2) == 1 {
                result.push('1');
            } else {
                result.push('0');
            }
            carry /= 2;
        }
        result.chars().rev().collect::<String>()
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_add_binary() {
        assert_eq!(
            Solution::add_binary(String::from("11"), String::from("1")),
            String::from("100")
        );
        assert_eq!(
            Solution::add_binary(String::from("1010"), String::from("1011")),
            String::from("10101")
        );
    }
}
