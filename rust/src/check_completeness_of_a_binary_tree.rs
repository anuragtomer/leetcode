use crate::util::tree::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    #[allow(dead_code)]
    pub fn is_complete_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return true;
        }
        let mut current = vec![root];
        let mut i: usize = 0;
        while i < current.len() {
            let node = current[i].clone();
            i += 1;
            if node.is_none() {
                while i < current.len() {
                    let node = current[i].clone();
                    i += 1;
                    if !node.is_none() {
                        return false;
                    }
                }
            } else {
                if let Some(n) = node {
                    let mut tmp = vec![n.borrow().left.clone(), n.borrow().right.clone()];
                    current.append(&mut tmp);
                }
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
