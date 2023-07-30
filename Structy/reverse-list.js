class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

const reverseList = (head) => {
  let prevNode = null;
  let currNode = head;
  
  while(currNode) {
    let saved = currNode.next;
    
    currNode.next = prevNode;
    prevNode = currNode;
    currNode = saved;
  }
  
  return prevNode;
};

module.exports = {
  reverseList,
};
