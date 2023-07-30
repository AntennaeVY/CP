class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

const sumList = (head) =>{ 
  let ans = 0;
  let curr = head;
  
  while(curr) {
    ans += curr.val;
    curr = curr.next;
  }
  
  return ans;
};

module.exports = {
  sumList,
};
