impl Solution {
    pub fn remove_elements(
        head: Option<Box<ListNode>>,
        val: i32
    ) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: head,
        });

        let mut curr = &mut dummy;

        while let Some(node) = curr.next.as_ref() {
            if node.val == val {
                curr.next = curr.next.take().unwrap().next;
            } else {
                curr = curr.next.as_mut().unwrap();
            }
        }

        dummy.next
    }
}