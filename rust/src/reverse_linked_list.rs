use crate::util::linked_list::ListNode;

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut prev, mut curr) = (None, head);
        while let Some(mut node) = curr {
            curr = node.next;
            node.next = prev;
            prev = Some(node);
        }
        prev
    }
}
pub struct Solution {}

#[cfg(test)]
mod tests {
    use crate::util::linked_list::to_list;

    use super::*;
    #[test]
    fn test_reverse_list() {
        assert_eq!(
            to_list(vec![1, 2, 3, 4, 5]),
            Solution::reverse_list(to_list(vec![5, 4, 3, 2, 1]))
        );
        assert_eq!(
            to_list(vec![1, 2]),
            Solution::reverse_list(to_list(vec![2, 1]))
        );
        assert_eq!(to_list(vec![]), Solution::reverse_list(to_list(vec![])));
    }
}
