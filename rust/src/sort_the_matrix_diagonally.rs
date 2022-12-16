impl Solution {
    pub fn diagonal_sort(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let h = mat.len();
        let w = mat[0].len();
        let mut result = vec![vec![0; w]; h];
        let diag_len = std::cmp::min(h, w);
        if diag_len == 1 {
            return mat;
        }
        let mut diag = Vec::with_capacity(diag_len);
        for col in 0..w {
            for offset in 0..std::cmp::min(diag_len, w - col) {
                diag.push(mat[offset][col + offset]);
            }
            diag.sort();
            for (offset, elem) in diag.iter().enumerate() {
                result[offset][col + offset] = *elem;
            }
            diag.clear();
        }
        for row in 1..h {
            for offset in 0..std::cmp::min(diag_len, h - row) {
                diag.push(mat[row + offset][offset]);
            }
            diag.sort();
            for (offset, elem) in diag.iter().enumerate() {
                result[row + offset][offset] = *elem;
            }
            diag.clear();
        }
        result
    }
}
pub struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_() {
        assert_eq!(
            Solution::diagonal_sort(vec![vec![3, 3, 1, 1], vec![2, 2, 1, 2], vec![1, 1, 1, 2]]),
            vec![vec![1, 1, 1, 1], vec![1, 2, 2, 2], vec![1, 2, 3, 3]]
        );

        assert_eq!(
            Solution::diagonal_sort(vec![
                vec![11, 25, 66, 1, 69, 7],
                vec![23, 55, 17, 45, 15, 52],
                vec![75, 31, 36, 44, 58, 8],
                vec![22, 27, 33, 25, 68, 4],
                vec![84, 28, 14, 11, 5, 50]
            ]),
            vec![
                vec![5, 17, 4, 1, 52, 7],
                vec![11, 11, 25, 45, 8, 69],
                vec![14, 23, 25, 44, 58, 15],
                vec![22, 27, 31, 36, 50, 66],
                vec![84, 28, 75, 33, 55, 68]
            ]
        );
    }
}
