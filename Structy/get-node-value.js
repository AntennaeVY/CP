class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

const getNodeValue = (head, index) => {
  let i = 0;
  let curr = head;
  
  while(curr) {
    if (index == i++) return curr.val;
    curr = curr.next;
  }
  
  return null;
};

module.exports = {
  getNodeValue,
};
