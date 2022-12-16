use std::{cell::RefCell, rc::Rc};

use crate::util::tree::TreeNode;

trait TreeNodeSwap {
    fn swap(&mut self);
    fn swap_all(&mut self);
}

impl TreeNodeSwap for TreeNode {
    fn swap(&mut self) {
        std::mem::swap(&mut self.left, &mut self.right);
    }
    fn swap_all(&mut self) {
        self.left.as_mut().map(|node| node.borrow_mut().swap_all());
        self.right.as_mut().map(|node| node.borrow_mut().swap_all());
        self.swap();
    }
}

impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        root.map(|node| {
            node.borrow_mut().swap_all();
            node
        })
    }
}

pub struct Solution {}

#[cfg(test)]
mod test {
    use super::*;
    use crate::util::tree::to_tree;

    #[test]
    fn test_invert_tree() {
        assert_eq!(
            tree![4, 7, 2, 9, 6, 3, 1],
            Solution::invert_tree(tree![4, 2, 7, 1, 3, 6, 9])
        );

        assert_eq!(tree![2, 3, 1], Solution::invert_tree(tree![2, 1, 3]));
        assert_eq!(tree![], Solution::invert_tree(tree![]));
    }
}
