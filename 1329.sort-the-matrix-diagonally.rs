impl Solution {
  pub fn diagonal_sort(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let h = mat.len();
    let w= mat[0].len();
    let mut result = vec![vec![0;w];h];
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
