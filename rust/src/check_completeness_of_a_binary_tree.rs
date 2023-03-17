use crate::util::tree::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    #[allow(dead_code)]
    pub fn is_complete_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return true;
        }
        let mut all_nodes = vec![root];
        let mut i: usize = 0;
        while i < all_nodes.len() {
            let node = all_nodes[i].as_ref();
            i += 1;
            if node.is_none() {
                while i < all_nodes.len() {
                    if all_nodes[i].is_some() {
                        return false;
                    }
                    i += 1;
                }
                return true;
            } else if let Some(n) = node {
                let mut tmp = vec![n.borrow().left.clone(), n.borrow().right.clone()];
                all_nodes.append(&mut tmp);
            }
        }
        true
    }
}

#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod test {
    use super::*;
    use crate::util::tree::to_tree;
    #[test]
    fn test_is_complete_tree() {
        assert_eq!(Solution::is_complete_tree(tree![1, 2, 3, 4, 5, 6]), true);
        assert_eq!(
            Solution::is_complete_tree(tree![1, 2, 3, 4, 5, None, 6]),
            false
        );
    }
}
