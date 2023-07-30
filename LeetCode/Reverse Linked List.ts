/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
  let prev = null,
    next = null,
    curr = head;

  if (!curr) return curr;

  while (curr.next) {
    next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
  }

  curr.next = prev;

  return curr;
}
