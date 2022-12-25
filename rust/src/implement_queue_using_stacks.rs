struct MyQueue {
    stack_one: Vec<i32>,
    stack_two: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {
    fn new() -> Self {
        Self {
            stack_one: vec![],
            stack_two: vec![],
        }
    }

    fn push(&mut self, x: i32) {
        self.stack_one.push(x);
    }

    fn pop(&mut self) -> i32 {
        if self.stack_two.is_empty() {
            loop {
                match self.stack_one.pop() {
                    Some(val) => self.stack_two.push(val),
                    None => break,
                };
            }
        }
        self.stack_two.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        if self.stack_two.is_empty() {
            loop {
                match self.stack_one.pop() {
                    Some(val) => self.stack_two.push(val),
                    None => break,
                };
            }
        }
        self.stack_two.last().unwrap().clone()
    }

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
