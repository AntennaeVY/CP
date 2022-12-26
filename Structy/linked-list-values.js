class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

const linkedListValues = (head) => {
  const ans = [];
  let curr = head;
  
  while(curr) {
    ans.push(curr.val);
    curr = curr.next;
  }
  
  return ans;
};

module.exports = {
  linkedListValues,
};
