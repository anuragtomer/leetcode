impl Solution {
    fn new(n: i32) -> Self {
        Self { bad_version: n }
    }
    pub fn is_bad_version(&self, n: i32) -> bool {
        n >= self.bad_version
    }
    pub fn first_bad_version(&self, n: i32) -> i32 {
        let (mut lb, mut ub) = (0, n);
        loop {
            let mid = lb + (ub - lb) / 2;
            match self.is_bad_version(mid) {
                true => ub = mid,
                false => lb = mid + 1,
            };
            if lb >= ub {
                break;
            }
        }
        lb
    }
}

struct Solution {
    bad_version: i32,
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test_first_bad_version() {
        let first = Solution::new(4);
        assert_eq!(4, first.first_bad_version(5));
        let first = Solution::new(1);
        assert_eq!(1, first.first_bad_version(1));
    }
}
