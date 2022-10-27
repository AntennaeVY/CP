/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var prev *ListNode = nil
    var next *ListNode = nil
    
    curr := head
    
    if (curr == nil){
        return curr
    }
    
    for curr.Next != nil {
        next = curr.Next
        curr.Next = prev
        prev = curr
        curr = next
    }
    
    curr.Next = prev
    
    return curr
}