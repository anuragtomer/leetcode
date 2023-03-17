use crate::util::tree::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    #[allow(dead_code)]
    pub fn build_tree_2(
        inorder: Vec<i32>,
        postorder: &mut Vec<i32>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder.is_empty() || postorder.is_empty() {
            return None;
        }
        let root_val = postorder.last().unwrap();
        let mut found_at: Option<usize> = None;
        for (i, val) in inorder.iter().enumerate() {
            if val == root_val {
                found_at = Some(i);
                break;
            }
        }
        found_at?;
        let mut root = TreeNode {
            val: *root_val,
            left: None,
            right: None,
        };
        postorder.pop();
        root.right = Self::build_tree_2(inorder[found_at.unwrap() + 1..].to_vec(), postorder);
        root.left = Self::build_tree_2(inorder[0..found_at.unwrap()].to_vec(), postorder);
        Some(Rc::new(RefCell::new(root)))
    }
    #[allow(dead_code)]
    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Solution::builder(&inorder[..], &postorder[..])
    }
    #[allow(dead_code)]
    fn builder(inorder: &[i32], postorder: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder.is_empty() || postorder.is_empty() {
            None
        } else {
            let i = inorder.len();
            let n = postorder.len() - 1;
            let mut root = TreeNode::new(postorder[n]);
            let m = inorder.iter().position(|&x| x == postorder[n]).unwrap();
            root.left = Solution::builder(&inorder[0..m], &postorder[0..m]);
            root.right = Solution::builder(&inorder[m + 1..i], &postorder[m..i - 1]);
            Some(Rc::new(RefCell::new(root)))
        }
    }
}
#[allow(dead_code)]
struct Solution {}
#[cfg(test)]
mod test {
    use super::*;
    use crate::util::tree::to_tree;

    #[test]
    fn test_build_tree() {
        let mut postorder = vec![9, 15, 7, 20, 3];
        assert_eq!(
            Solution::build_tree_2(vec![9, 3, 15, 20, 7], &mut postorder),
            tree![3, 9, 20, None, None, 15, 7]
        );
        let mut postorder = vec![-1];
        assert_eq!(Solution::build_tree_2(vec![-1], &mut postorder), tree![-1]);
        assert_eq!(
            Solution::build_tree(vec![9, 3, 15, 20, 7], vec![9, 15, 7, 20, 3]),
            tree![3, 9, 20, None, None, 15, 7]
        );
        assert_eq!(Solution::build_tree(vec![-1], vec![-1]), tree![-1]);
    }
}
