use crate::util::tree::TreeNode;

use std::{cell::RefCell, rc::Rc};
impl Solution {
    #[allow(dead_code)]
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn compare(
            left: Option<Rc<RefCell<TreeNode>>>,
            right: Option<Rc<RefCell<TreeNode>>>,
        ) -> bool {
            match (left, right) {
                (None, None) => true,
                (None, Some(_)) | (Some(_), None) => false,
                (Some(left), Some(right)) => {
                    if left.borrow().val != right.borrow().val {
                        return false;
                    }
                    return compare(left.borrow().left.clone(), right.borrow().right.clone())
                        && compare(left.borrow().right.clone(), right.borrow().left.clone());
                }
            }
        }
        match root {
            None => true,
            Some(node) => compare(node.borrow().left.clone(), node.borrow().right.clone()),
        }
    }
}
#[allow(dead_code)]
struct Solution {}
#[cfg(test)]
mod tests {
    use super::*;
    use crate::util::tree::print_tree;
    use crate::util::tree::to_tree;
    use log::info;
    #[test]
    fn test_is_symmetric() {
        env_logger::init();
        assert_eq!(Solution::is_symmetric(tree![1, 2, 2, 4, 3, 3, 4]), true);
        assert_eq!(
            Solution::is_symmetric(tree![1, 2, 2, None, 3, 3, None]),
            true
        );
        info!("Unable to print anything.");
        print_tree(tree![1, 2, 2, None, 3, 3, None]);
    }
}
