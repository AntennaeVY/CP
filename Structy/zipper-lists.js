// class Node {
//   constructor(val) {
//     this.val = val;
//     this.next = null;
//   }
// }

const zipperLists = (head1, head2) => {
  // head1 -> head2 -> head1.next -> head2.next
  const newHead = head1;
  let next1 = head1.next, next2 = head2.next;
  
  while(next1 && next2) { 
    head1.next = head2;
    head2.next = next1;
    
    head1 = next1;
    head2 = next2;
    
    next1 = head1.next;
    next2 = head2.next;
  } 
  
  head1.next = head2;
  head1 = head1.next;
  
  while(next1) {
    head1.next = next1;
    head1 = head1.next;
    next1 = next1.next;
  }
  
  while(next2) {
    head1.next = next2;
    head1 = head1.next;
    next2 = next2.next; 
  }
  
  return newHead;
};

module.exports = {
  zipperLists,
};
