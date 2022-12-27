impl Solution {
    fn fill(image: &mut Vec<Vec<i32>>, sr: i32, sc: i32, old_color: i32, new_color: i32) {
        if sr >= image.len() as i32
            || sr < 0
            || sc >= image[sr as usize].len() as i32
            || sc < 0
            || image[sr as usize][sc as usize] != old_color
        {
            return;
        } else {
            image[sr as usize][sc as usize] = new_color;
            Self::fill(image, sr + 1, sc, old_color, new_color);
            Self::fill(image, sr - 1, sc, old_color, new_color);
            Self::fill(image, sr, sc + 1, old_color, new_color);
            Self::fill(image, sr, sc - 1, old_color, new_color);
        }
    }
    pub fn flood_fill(image: Vec<Vec<i32>>, sr: i32, sc: i32, color: i32) -> Vec<Vec<i32>> {
        let mut image_clone = image.clone();
        if image[sr as usize][sc as usize] != color {
            let old_color = image[sr as usize][sc as usize];
            Self::fill(&mut image_clone, sr, sc, old_color, color);
        }
        image_clone
    }
}
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_flood_fill() {
        assert_eq!(
            Solution::flood_fill(vec![vec![1, 1, 1], vec![1, 1, 0], vec![1, 0, 1]], 1, 1, 2),
            vec![vec![2, 2, 2], vec![2, 2, 0], vec![2, 0, 1]]
        );
        assert_eq!(
            Solution::flood_fill(vec![vec![0, 0, 0], vec![0, 0, 0]], 0, 0, 0),
            vec![vec![0, 0, 0], vec![0, 0, 0]]
        );
    }
}
