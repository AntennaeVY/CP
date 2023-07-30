class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

const linkedListFind = (head, target) => {
  let curr = head;
  
  while(curr) {
    if (curr.val == target) return true;
    curr = curr.next;
  }
  
  return false;
};

module.exports = {
  linkedListFind,
};
