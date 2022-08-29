impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut result:String = "".to_string();
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
