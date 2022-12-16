#[derive(Default)]
struct MyCircularQueue {
    queue: Vec<i32>,
    front: usize,
    len: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCircularQueue {
    fn new(k: i32) -> Self {
        Self {
            queue: vec![0; k as _],
            ..Default::default()
        }
    }

    fn en_queue(&mut self, value: i32) -> bool {
        if self.is_full() {
            false
        } else {
            let cap = self.queue.len();
            self.len += 1;
            self.queue[(self.front + self.len - 1) % cap] = value;
            true
        }
    }

    fn de_queue(&mut self) -> bool {
        if self.is_empty() {
            false
        } else {
            self.len -= 1;
            self.front = (self.front + 1) % self.queue.len();
            true
        }
    }

    fn front(&self) -> i32 {
        if self.is_empty() {
            -1
        } else {
            self.queue[self.front]
        }
    }

    fn rear(&self) -> i32 {
        if self.is_empty() {
            -1
        } else {
            self.queue[(self.front + self.len - 1) % self.queue.len()]
        }
    }

    fn is_empty(&self) -> bool {
        self.len == 0
    }

    fn is_full(&self) -> bool {
        self.len == self.queue.len()
    }
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_circular_queue() {
        let mut obj = MyCircularQueue::new(3);
        assert!(obj.en_queue(1));
        assert!(obj.en_queue(2));
        assert!(obj.en_queue(3));
        assert!(!obj.en_queue(4));
        assert_eq!(3, obj.rear());
        assert!(obj.is_full());
        assert!(obj.de_queue());
        assert_eq!(2, obj.front());
        assert!(obj.en_queue(4));
        assert_eq!(4, obj.rear());
    }
}
