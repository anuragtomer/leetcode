impl Solution {
    #[allow(dead_code)]
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map = std::collections::HashMap::new();
        s.chars().for_each(|c| *map.entry(c).or_insert(0) += 1);
        t.chars().for_each(|c| *map.entry(c).or_insert(0) -= 1);
        map.into_values().all(|v| v == 0)
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_is_anagram() {
        assert!(Solution::is_anagram(
            String::from("nagaram"),
            String::from("anagram")
        ));
        assert!(!Solution::is_anagram(
            String::from("rat"),
            String::from("car")
        ));
    }
}
