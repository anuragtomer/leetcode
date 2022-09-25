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
        if (self.is_empty()) {
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

fn main() {
    let obj = MyCircularQueue::new(k);
    let ret_1: bool = obj.en_queue(value);
    let ret_2: bool = obj.de_queue();
    let ret_3: i32 = obj.front();
    let ret_4: i32 = obj.rear();
    let ret_5: bool = obj.is_empty();
    let ret_6: bool = obj.is_full();
}
