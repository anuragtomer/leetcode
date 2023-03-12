#[allow(dead_code)]
struct MyQueue {
    stack_one: Vec<i32>,
    stack_two: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {
    #[allow(dead_code)]
    fn new() -> Self {
        Self {
            stack_one: vec![],
            stack_two: vec![],
        }
    }
    #[allow(dead_code)]
    fn push(&mut self, x: i32) {
        self.stack_one.push(x);
    }
    #[allow(dead_code)]
    fn pop(&mut self) -> i32 {
        if self.stack_two.is_empty() {
            while let Some(val) = self.stack_one.pop() {
                self.stack_two.push(val);
            }
        }
        self.stack_two.pop().unwrap()
    }
    #[allow(dead_code)]
    fn peek(&mut self) -> i32 {
        if self.stack_two.is_empty() {
            while let Some(val) = self.stack_one.pop() {
                self.stack_two.push(val);
            }
        }
        *self.stack_two.last().unwrap()
    }
    #[allow(dead_code)]
    fn empty(&self) -> bool {
        self.stack_one.is_empty() && self.stack_two.is_empty()
    }
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test_queue_using_stack() {
        let mut obj = MyQueue::new();
        obj.push(1);
        obj.push(2);
        assert_eq!(1, obj.peek());
        assert_eq!(1, obj.pop());
        assert_eq!(false, obj.empty());
    }
}
