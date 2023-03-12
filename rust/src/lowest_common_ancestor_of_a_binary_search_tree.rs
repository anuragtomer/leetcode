// Definition for a binary tree node.
use std::cell::RefCell;
use std::rc::Rc;

use crate::util::tree::TreeNode;

impl Solution {
    #[allow(dead_code)]
    pub fn lowest_common_ancestor(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let (p, q) = match (p.unwrap().borrow().val, q.unwrap().borrow().val) {
            (p, q) if p > q => (q, p),
            t => t,
        };

        loop {
            let expected = root.as_ref().unwrap().borrow().val;
            if p <= expected && expected <= q {
                return root;
            }
            root = match q < expected {
                true => root.unwrap().borrow().left.clone(),
                _ => root.unwrap().borrow().right.clone(),
            };
        }
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {

    use super::*;
    use crate::util::tree::to_tree;
    #[test]
    fn test_lowest_common_ancestor() {
        assert_eq!(
            Solution::lowest_common_ancestor(
                tree![6, 2, 8, 0, 4, 7, 9, null, null, 3, 5],
                tree![2, 0, 4, null, null, 3, 5],
                tree![8, 7, 9]
            ),
            tree![6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]
        );
    }
}
