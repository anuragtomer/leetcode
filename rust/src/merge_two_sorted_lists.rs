use crate::util::linked_list::ListNode;

impl Solution {
    #[allow(dead_code)]
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match list1 {
            Some(mut list1_head) => match list2 {
                Some(mut list2_head) => {
                    if list1_head.val < list2_head.val {
                        list1_head.next =
                            Solution::merge_two_lists(list1_head.next, Some(list2_head));
                        Some(list1_head)
                    } else {
                        list2_head.next =
                            Solution::merge_two_lists(Some(list1_head), list2_head.next);
                        Some(list2_head)
                    }
                }
                None => Some(list1_head),
            },
            None => list2,
        }
    }
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]
mod tests {
    use crate::util::linked_list::to_list;

    use super::*;
    #[test]
    fn test_merge_two_sorted_lists() {
        assert_eq!(
            Solution::merge_two_lists(to_list(vec![1, 2, 4]), to_list(vec![1, 3, 5])),
            to_list(vec![1, 1, 2, 3, 4, 5])
        );

        assert_eq!(
            Solution::merge_two_lists(to_list(vec![]), to_list(vec![])),
            to_list(vec![])
        );

        assert_eq!(
            Solution::merge_two_lists(to_list(vec![]), to_list(vec![0])),
            to_list(vec![0])
        );
    }
}
