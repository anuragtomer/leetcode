use std::collections::VecDeque;
impl Solution {
    #[allow(dead_code)]
    fn serialize_board(board: Vec<Vec<i32>>) -> Vec<i32> {
        let mut flatboard: Vec<i32> = Vec::new();
        let mut toggle = true;
        for row in board.iter().rev() {
            if toggle {
                flatboard.extend(row.iter());
            } else {
                flatboard.extend(row.iter().rev());
            }
            toggle = !toggle;
        }
        flatboard
    }
    #[allow(dead_code)]
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let h = board.len();
        if h == 0 {
            return 0;
        }
        let w = board[0].len();
        let flatboard = Solution::serialize_board(board);
        let (mut queue, mut distance) = (VecDeque::new(), vec![-1; h * w]);
        queue.push_back(0);
        distance[0] = 0;

        while let Some(index) = queue.pop_front() {
            for i in index + 1..(index + 7).min(h * w) {
                let mut new_index = i;

                if flatboard[new_index] != -1 {
                    new_index = (flatboard[new_index] - 1) as usize;
                }

                if new_index == (h * w) - 1 {
                    return distance[index] + 1;
                }

                if distance[new_index] == -1 {
                    queue.push_back(new_index);
                    distance[new_index] = distance[index] + 1;
                }
            }
        }

        -1
    }
}
#[allow(dead_code)]
struct Solution {}
#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test_snakes_and_ladders() {
        assert_eq!(
            Solution::snakes_and_ladders(vec![
                vec![-1, -1, -1, -1, -1, -1],
                vec![-1, -1, -1, -1, -1, -1],
                vec![-1, -1, -1, -1, -1, -1],
                vec![-1, 35, -1, -1, 13, -1],
                vec![-1, -1, -1, -1, -1, -1],
                vec![-1, 15, -1, -1, -1, -1]
            ]),
            4
        );
        assert_eq!(
            Solution::snakes_and_ladders(vec![vec![-1, -1], vec![-1, 3]]),
            1
        );
    }
}
