use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut seen = HashMap::new();
        for chars in magazine.chars() {
            seen.entry(chars).and_modify(|e| *e += 1).or_insert(1);
        }
        for chars in ransom_note.chars() {
            match seen.get_mut(&chars) {
                Some(n) if *n > 0 => {
                    *n -= 1;
                }
                _ => {
                    return false;
                }
            }
        }
        true
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_can_construct() {
        {
            let ransom_note = String::from("a");
            let magazine = String::from("b");
            assert!(!Solution::can_construct(ransom_note, magazine));
        }
        {
            let ransom_note = String::from("aa");
            let magazine = String::from("ab");
            assert!(!Solution::can_construct(ransom_note, magazine));
        }
        {
            let ransom_note = String::from("aa");
            let magazine = String::from("aab");
            assert!(Solution::can_construct(ransom_note, magazine));
        }
    }
}
